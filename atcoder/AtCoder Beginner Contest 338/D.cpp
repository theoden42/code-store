

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    for(int i = 0; i < m; i++){
    	cin >> x[i];
    }

    vector<int> d1(n + 2);
    vector<int> d2(n + 2);
    int curr = x[0];	
    int total = 0;
    for(int i = 1; i < m; i++){
    	int cl = abs(x[i] - curr);
    	int ant = n - cl;

        int t = max(x[i], curr);
        int s = min(x[i], curr);
    	if(cl < ant){
            d1[t] -= cl;
            d1[s] += cl;
            d2[t] -= 1;
            d2[s] += 1;
        } else {
            d1[s] -= ant;
            d1[1] += ant;
            d1[n + 1] -= ant;
            d1[t] += ant;

            d2[s] -= 1;
            d2[1] += 1;
            d2[n + 1] -= 1;
            d2[t] += 1;
        }

        total += min(cl, ant);
        curr = x[i];
    }

    for(int i = 1; i <= n + 1; i++){
    	d1[i] = d1[i - 1] + d1[i];	
    	d2[i] = d2[i - 1] + d2[i];
    }

    int mnans = 1e18;
    for(int i = 1; i <= n; i++){
    	int nwcost = total + d2[i] * n - 2 * (d1[i]);
    	mnans = min(mnans, nwcost);
    }

    cout << mnans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}