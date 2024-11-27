

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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(k + 1);
    vector<int> b(k + 1);
    for(int i = 1; i <= k; i++)
    	cin >> a[i];
    for(int i = 1; i <= k; i++)
    	cin >> b[i];

    for(int i = 1; i <= q; i++){
    	int d;
    	cin >> d;
        if(d == n){
            cout << b.back() << " ";
            continue;
        }
    	auto it = upper_bound(all(a), d);
    	int ind = it - a.begin();
    	int prevtime = b[ind - 1];
    	int moretime = (b[ind] - b[ind - 1]) * (d - a[ind - 1]) / (a[ind] - a[ind - 1]);
    	int ans = prevtime + moretime;
    	cout << ans << " ";
    }
    cout << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}