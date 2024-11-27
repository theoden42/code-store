

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
	    vector<vector<int>> a(n, vector<int>(2, 0));
	    for(int i = 0; i < n; i++){
	    	cin >> a[i][0] >> a[i][1];
	    }

	    vector<vector<int>> adj(n);
	    for(int i = 0; i < n - 1; i++){
	    	int u, v;
	    	cin >> u >> v;
	    	u--;
	    	v--;
	    	adj[u].push_back(v);
	    	adj[v].push_back(u);
	    }

	    vector<vector<int>> dp(n, vector<int> (2, -1));

	    function<int(int, int, int)> dfs = [&](int source, int parent, int state) { 
	    	if(dp[source][state] != -1)
	    		return dp[source][state];

	    	int mx = 0;
	    	if(parent == -1){
	    		int count1 = 0;
	    		int count2 = 0;
	    		for(auto x: adj[source]){
	    			count1 += dfs(x, source, 0);
	    			count2 += dfs(x, source, 1);
	    		}
	    		mx = max(count1, count2);
	    		return dp[source][state] = mx;
	    	}

	    	int pv = a[parent][state];
	    	for(int i = 0; i < 2; i++){
	    		int count = abs(a[source][i] - pv);
	    		for(auto x: adj[source]){
	    			if(x != parent){
	    				count += dfs(x, source, i);
	    			}
	    		}
	    		mx = max(mx, count);
	    	}
	    	return dp[source][state] = mx;
	    };

	    int ans = dfs(1, -1, 0);
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