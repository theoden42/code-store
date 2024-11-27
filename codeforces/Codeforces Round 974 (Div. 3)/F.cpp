

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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    function<int(int,int,int)>	dfs
    = [&](int source, int t, int p)->int{
    	// debug(source, t, p);
    	if(dp[source][t] != -1)
    		return dp[source][t];
    	int mx = (t ? a[source - 1] : 0);
        // debug(source, t, mx);
    	for(auto x: adj[source]) if(x != p) { 
    		int x0 = dfs(x, 0, source);
    		int x1 = dfs(x, 1, source);
    		if(t)
    			mx += max(x0, x1 - 2 * c);
    		else 
    			mx += max(x0, x1);
    	}
    	return dp[source][t] = mx;
    }; dfs(1, 0, -1); dfs(1, 1, -1);
    // debug(dp);
    cout << max(dp[1][0], dp[1][1]) << endl;
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