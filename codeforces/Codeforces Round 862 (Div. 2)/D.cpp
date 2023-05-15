

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
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i ++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> height(n);
    vector<int> dist(n);

    function<int(int, int)> dfs1 = [&](int source, int par)->int{

    	height[source] = 1;

    	for(auto& x: adj[source]){

    		if(x == par)continue;

    		height[source] = max(height[source], 1 + dfs1(x, source));
    	}

    	return height[source];
    };

    dfs1(0, -1);

    function<void(int, int)> dfs2 = [&](int cur, int par){
    	int max1 = 0;
	    int max2 = 0;

	    for (auto u : adj[cur]) {
	 
	        if (u != par) {

	            if (height[u] >= max1) {
	                max2 = max1;
	                max1 = height[u];
	            }
	            else if (height[u] > max2) {
	                max2 = height[u];
	            }
	        }
	    }
	 
	    for (auto u : adj[cur]) {
	        if (u != par) {
	 
	 
	            if (max1 == height[u])
	                dist[u]
	                    = 1 + max(1 + max2, dist[cur]);
	            else
	                dist[u]
	                    = 1 + max(1 + max1, dist[cur]);
	 
	            dfs2(u, cur);
	        }
	    }
    };

    dfs2(0, -1);
    // debug(dist);

    vector<int> max_dist(n);
    for(int i = 0; i < n; i++){
    	max_dist[i] = max(height[i] - 1, dist[i] - 1);
    }

    sort(all(max_dist));

    // debug(height, max_dist);

    for(int i = 1; i <= n; i++){
    	int nd = (int)(max_dist.end() - lower_bound(all(max_dist), i)) + 1;
    	cout << min(n, n - nd + 2) << " ";
    }
    cout << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}