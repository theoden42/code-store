

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
const ll INF = 1e18;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }
    vector<int> s(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> s[i];
    }

    int mx = *max_element(all(s));
    vector<vector<int>> dist(n + 1, vector<int>(mx + 1, INF));
    vector<vector<int>> vis(n + 1, vector<int>(mx + 1, 0));
    multiset<vector<int>> pq;
    dist[1][mx] = 0;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= mx; j++){
    		pq.insert({dist[i][j], i, j});
    	}
    }

    while(!pq.empty()){
    	auto v = *pq.begin();
    	pq.erase(pq.begin());
    	int d = v[0];
    	int node = v[1];
    	int cycle = v[2];
    	vis[node][cycle] = 1;
    	int nw_cycle = min(s[node], cycle);

    	if(d == INF)
    		continue;

    	for(auto [x, w]: adj[node]){
    		if(!vis[x][nw_cycle]){
    			if(dist[x][nw_cycle] > d + nw_cycle * w){
    				pq.erase(pq.find({dist[x][nw_cycle], x, nw_cycle}));
    				dist[x][nw_cycle] = d + w * nw_cycle;
    				pq.insert({dist[x][nw_cycle], x, nw_cycle});
    			}
    		}
    	}
    }

    int ans = INF;
    for(int i = 1; i <= mx; i++){
    	ans = min(ans, dist[n][i]);
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