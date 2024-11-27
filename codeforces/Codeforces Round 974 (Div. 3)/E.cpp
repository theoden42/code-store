

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

vector<vector<int>> djik(int n, vector<vector<pair<int,int>>>& adj, map<int,int>& mp, int source){
	vector<vector<int>> dis(n + 1, vector<int>(2, 1e18)), vis(n + 1, vector<int>(2, 0));
	dis[source][0] = 0;
	vis[source][0] = 1;
	multiset<array<int,3>> mst;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 2; j++){
			mst.insert({dis[i][j], i, j});
		}
	}
	while(!mst.empty()){
		// debug(mst);
		auto temp_v = *mst.begin();	
		mst.erase(mst.begin());
		int d = temp_v[0];
		int nd = temp_v[1];
		int type = temp_v[2];	
		vis[nd][type] = 1;
		for(auto [ne, we]: adj[nd]){
			if(type || mp.find(nd) != mp.end()){
				if(we / 2 + d < dis[ne][1] && !vis[ne][1]){
					mst.erase(mst.find({dis[ne][1], ne, 1}));
					dis[ne][1] = d + we / 2;
					mst.insert({dis[ne][1], ne, 1});
				}
			}
			if(we + d < dis[ne][0] && !vis[ne][0]){
				mst.erase(mst.find({dis[ne][0], ne, 0}));
				dis[ne][0] = d + we;
				mst.insert({dis[ne][0], ne, 0});
			}
		}
	}

	return dis;
}

void solve() {
	int n, m, h;
	cin >> n >> m >> h;
	map<int,int> mp;
	for(int i = 0; i < h; i++){
		int x;
		cin >> x;
		mp[x] += 1;
	}
	vector<vector<pair<int,int>>> adj(n + 1);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	vector<vector<int>> dis1 = djik(n, adj, mp, 1);
	vector<vector<int>> dis2 = djik(n, adj, mp, n);
	int mn = 1e18;
	for(int i = 1; i <= n; i++){
		int mv1 = min(dis1[i][0], dis1[i][1]);
		int mv2 = min(dis2[i][1], dis2[i][0]);
		// debug(i, mv1, mv2);	
		if(mv1 != 1e18 && mv2 != 1e18)
			mn = min(mn, max(mv1, mv2));
	}
	cout << ((mn == 1e18) ? -1 : mn) << "\n";
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