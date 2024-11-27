

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
	    int n;
	    cin >> n;
	    vector<string> g(2);
	    cin >> g[0] >> g[1];

	    vector<pair<int,int>> dis = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

	    vector<vector<pair<int,int>>> go(2, vector<pair<int,int>>(n));
	    for(int i = 0; i < 2; i++){
	    	for(int j = 0; j < n; j++){
	    		if(g[i][j] == '<'){
	    			go[i][j] = {i, j - 1};
	    		} else {
	    			go[i][j] = {i, j + 1};
	    		}
	    	}
	    }

	    vector<vector<int>> vis(2, vector<int>(n));
	    queue<pair<int,int>> q;
	    q.push({0, 0});

	    while(!q.empty()){
	    	auto [r, c] = q.front();
	    	q.pop();
	    	for(auto [dx, dy]: dis){
	    		int nr = r + dx;
	    		int nc = c + dy;
	    		if(nr >= 0 && nr < 2 && nc >= 0 && nc < n){
	    			auto [fr, fc] = go[nr][nc];
	    			if(!vis[fr][fc]){
	    				vis[fr][fc] = 1;
	    				q.push({fr, fc});
	    			}
	    		}
	    	}
	    }

	    if(vis[1][n - 1]){
	    	cout << "YES\n";
	    } else {
	    	cout << "NO\n";
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