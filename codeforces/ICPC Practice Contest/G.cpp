

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
    int n, m, a, c, x0;
    cin >> n >> m >> a >> c >> x0;
    vector<int> x(n + 1);
    x[0] = x0;
    for(int i = 1; i <= n; i++){
    	x[i] = (x[i - 1] * a + c) % m;
    }

    int ans = 0;

    function<int(int,int,int)> dfs 
    = [&](int l, int r, int tgt)->int{
    	if(r < l)
    		return -1;
        // debug(l, r);
    	int mid = (l + r) / 2;
        if(tgt == x[mid])
            return mid;
        if(tgt < x[mid]){
            return dfs(l, mid - 1, tgt);
        } else {
            return dfs(mid + 1, r, tgt);
        }
    };

    for(int i = 1; i <= n; i++){
        int ind = dfs(1, n, x[i]);
        if(ind != -1){
            // debug(x[i], ind);
            ans += 1;
        }
    }
    cout << ans << "\n";

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