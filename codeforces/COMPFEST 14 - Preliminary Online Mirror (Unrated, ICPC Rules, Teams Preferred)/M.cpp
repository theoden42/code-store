

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

#define int long long 

const ll INF = 1e18;


void solve() {
    int n, m;
    cin >> n >> m;
    map<pair<int,int>, vector<pair<pair<int,int>,int>>> adj;

    for(int i = 1; i <= m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[{u, 0}].push_back({{v, 0}, w});
        adj[{v, 1}].push_back({{u, 1}, w});
        adj[{u, 0}].push_back({{u, 1}, 0});
        adj[{v, 0}].push_back({{v, 1}, 0});
    }   

    vector<vector<int>> vis(n + 1, vector<int>(2, 0));
    vector<vector<int>> dis(n + 1, vector<int>(2, INF));

    dis[1][0] = 0;
    dis[1][1] = 0;

    multiset<pair<int, pair<int,int>>> mst;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 2; j++){
            mst.insert({dis[i][j], {i, j}});
        }
    }

    while(!mst.empty()){
    	auto [dist, vert] = *(mst.begin());
        auto [v, type] = vert;
    	mst.erase(mst.begin());
    	vis[v][type] = 1;

    	for(auto [temp, weight] : adj[vert]){
            auto [x, typex] = temp;

    		if(!vis[x][typex]){
                debug(mst, x, typex);
    			if(dis[x][typex] > dis[v][type] + weight){
    				mst.erase(mst.find({dis[x][typex], {x, typex}}));
	    			dis[x][typex] = dis[v][type] + weight;
	    			mst.insert({dis[x][typex], {x, typex}});
    			}
    		}
    	}
    }

    debug(dis);

    for(int i = 2; i <= n; i++){
        int ans = min(dis[i][0], dis[i][1]);
        if(ans == INF){
            cout << "-1 ";
        }
        else{
            cout << ans << " ";
        }
    }

    cout << "\n";

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