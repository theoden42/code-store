

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

int dfs(int source, int col, int parent, vector<vector<int>>& adj, vector<vector<int>>& dp){
	if(dp[source][col] != -1)return dp[source][col];

	int val = 1;
	if(col == 0){
		for(auto x: adj[source]){
			if(x != parent){
				int v = dfs(x, 0, source, adj, dp);
				int v2 = dfs(x, 1, source, adj, dp);
				val = (val * (v + v2) % MOD) % MOD;
			}
		}
	}
	else{
		for(auto x: adj[source]){
			if(x != parent){
				int v = dfs(x, 0, source, adj, dp);
				val = (val * v) % MOD;
			}
		}
	}
	return dp[source][col] = val;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 1; i <= n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }


    vector<vector<int>> dp(n, vector<int>(2, -1));
    dp[0][0] = dfs(0, 0, -1, adj, dp);
    dp[0][1] = dfs(0, 1, -1, adj, dp);

    cout << (dp[0][0] + dp[0][1]) % MOD << "\n";
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