

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
	const int INF = 1e18;
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v, c});
    }
    vector<vector<int>> dis(n + 1, vector<int>(2, INF));
    vector<vector<int>> vis(n + 1, vector<int>(2, 0));

    multiset<vector<int>> q;
    dis[1][0] = 0;
    dis[1][1] = 0;
    for(int i = 1; i <= n; i++){
    	q.insert({dis[i][0], i, 0});
    	q.insert({dis[i][1], i, 1});
    }

    while(!q.empty()){
    	auto v = *q.begin();
    	q.erase(q.begin());
    	int type = v[2];
    	int node = v[1];
    	int dist = v[0];
    	vis[node][type] = 1;
    	if(type){
    		for(auto [x, w]: adj[node]){
    			if(!vis[x][type] && dis[x][type] > dist + w){
    				q.erase(q.find({dis[x][type], x, type}));
    				dis[x][type] = dist + w;
    				q.insert({dis[x][type], x, type});
    			}
    		}
    	} else {
    		for(auto [x, w]: adj[node]){
    			if(!vis[x][0] && dis[x][0] > dist + w){
    				q.erase(q.find({dis[x][0], x, 0}));
    				dis[x][0] = dist + w;
    				q.insert({dis[x][0], x, 0});
    			}
    		}
    		for(auto [x, w]: adj[node]){
    			if(!vis[x][1] && dis[x][1] > dist + w / 2){
    				q.erase(q.find({dis[x][1], x, 1}));
    				dis[x][1] = dist + w / 2;
    				q.insert({dis[x][1], x, 1});
    			}
    		}
    	}
    }


    int ans = min(dis[n][0], dis[n][1]);
    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}