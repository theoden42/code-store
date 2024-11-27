

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
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	vp[i] = {a, b};
    }
    vector<int> mnleft(n + 1, m + 1);
    mnleft[0] = 1;
    for(int i = 1; i <= n; i++){
        if(vp[i - 1].first <= mnleft[i - 1] && vp[i - 1].second >= mnleft[i - 1]){
            mnleft[i] = min(m + 1, vp[i - 1].second + 1);
        } else {
            mnleft[i] = mnleft[i - 1];
        }
    }

    // debug(mnleft);

    for(int i = 1; i <= n; i++){
        if(mnleft[i] == m + 1){
            cout << "-1\n";
            continue;
        } else {
            int total = i + mnleft[i] - 1;
            cout << total << "\n";
        }
    }

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}