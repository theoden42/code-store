

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

	void solve() {
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		vector<vector<int>> adj(n + 1);
		for(int i = 2; i <= n; i++){
			int x;
			cin >> x;
			adj[x].push_back(i);
			adj[i].push_back(x);
		}
		vector<int> pos(n + 1), parent_pos(n + 1), pnt(n + 1);
		int time = 1;
		function<void(int,int)> dfs = [&](int source, int parent){
			pos[source] = time++;
			pnt[source] = parent;
			if(parent != -1)
				parent_pos[time - 1] = pos[parent];
			for(auto x: adj[source]) if(x != parent){
				dfs(x, source);
			}
		}; dfs(1, -1);
		vector<int> p(n + 1);
		for(int i = 1; i <= n; i++)
			cin >> p[i];


		vector<vector<int>> mp(n + 1);
		set<int> count;
		for(int i = 2; i <= n; i++){
			if(p[parent_pos[i]] == pnt[p[i]])
				count.insert(i);
		}
		for(int i = 1; i <= n; i++){
			mp[parent_pos[i]].push_back(i);
		}

		for(int i = 1; i <= q; i++){
			int x, y;
			cin >> x >> y;
			if(x != 1){
				if(p[parent_pos[x]] == pnt[p[x]])
					count.erase(x);
			}
			for(auto c_pos: mp[x]){
				if(p[x] == pnt[p[c_pos]])
					count.erase(c_pos);
			}
			if(y != 1){
				if(p[parent_pos[y]] == pnt[p[y]])
					count.erase(y);
			}
			for(auto c_pos: mp[y]){
				if(p[y] == pnt[p[c_pos]])
					count.erase(c_pos);
			}
			swap(p[x], p[y]);
			debug(p);
			if(x != 1){
				if(p[parent_pos[x]] == pnt[p[x]])
					count.insert(x);
			}
			for(auto c_pos: mp[x]){
				if(p[x] == pnt[p[c_pos]])
					count.insert(c_pos);
			}
			if(y != 1){
				if(p[parent_pos[y]] == pnt[p[y]])
					count.insert(y);
			}
			for(auto c_pos: mp[y]){
				if(p[y] == pnt[p[c_pos]])
					count.insert(c_pos);
			}
			debug(count);
			if(p[1] == 1 && count.size() == n - 1){
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
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