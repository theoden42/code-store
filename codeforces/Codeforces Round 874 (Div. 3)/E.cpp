

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


	int dfs(int source, int parent, vector<vector<int>>& adj, vector<int>& vis){
		// debug(source);

		vis[source] = 1;
		int val = 0;
		for(auto& x: adj[source]){
			if(x == parent)continue;
			if(vis[x]) val = 1;
			else{
				val |= dfs(x, source, adj, vis);
			}
		}
		return val;
	}


	void solve() {
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}

		vector<vector<int>> adj(n + 1);

		for(int i = 1; i <= n; i++){
			int x = a[i];
			int f = 0;
			for(auto s: adj[i]){
				if(x == s) f = 1;
			}

			if(!f){
				adj[x].push_back(i);
				adj[i].push_back(x);
			}
		}

		// debug(adj);

		vector<int> vis(n + 1);
		int component = 0;
		int cycle = 0;

		for(int i = 1; i <= n; i++){
			if(vis[i])continue;
			component++;
			if(dfs(i, -1, adj, vis))cycle++;
		}

		cout << min(component, cycle + 1) << " ";
		cout << component << "\n";

	}


	int main() {
	    ios_base::sync_with_stdio(0);
	    cin.tie(0); cout.tie(0);
	    int tc = 1;
	    cin >> tc;
	    for (int t = 1; t <= tc; t++) {
	        // cout << "Case #" << t << ": ";
	        solve();
	    }
	}