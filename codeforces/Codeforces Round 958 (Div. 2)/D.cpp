

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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(21, 0));
    function<void(int,int)> dfs
    = [&](int src, int pnt){
        for(auto x: adj[src]) if(x != pnt){
            dfs(x, src);
        }
        for(int j = 1; j <= 20; j++){
            int temp = a[src - 1] * j;
            for(auto x: adj[src]) if(x != pnt){
                int mn = 1e18;
                for(int k = 1; k <= 20; k++) if(k != j){
                    mn = min(mn, dp[x][k]);
                }
                temp += mn;
            }
            dp[src][j] = temp;
        }
    }; dfs(1, -1);
    int ans = 1e18;
    for(int j = 1; j <= 20; j++){
        ans = min(ans, dp[1][j]);
    }
    cout << ans << "\n";

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