

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
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> height(n + 1), leaves(n + 1);
    function<int(int,int)> dfsheight
    = [&](int source, int parent)->int{
    	if(adj[source].size() == 1 && source != 1)
    		return 0;
    	int dist = n + 1;
    	debug(source);
    	for(auto node: adj[source]){
    		if(node == parent)
    			continue;
    		dist = min(dist, 1 + dfsheight(node, source));
    	}
    	return height[source] = dist;
    }; dfsheight(1, -1);

    function<int(int,int)> countleaves
    = [&](int source, int parent)->int{
    	if(adj[source].size() == 1 && source != 1)
    		return leaves[source] = 1;

    	int ans = 0;
    	for(auto node: adj[source]){
    		if(node != parent)
    			ans += countleaves(node, source);
    	}
    	return leaves[source] = ans;
    }; countleaves(1, -1);


    vector<int> capture(n + 1, -1);

    auto is_leaf = [&](int source){
    	return (adj[source].size() == 1 && source != 1);
    };

    function<void(int,int,int)> dfs
    = [&](int source, int parent, int dist){
    	if(dist >= height[source] && !is_leaf(source)){
    		capture[source] = leaves[source];
    	} else {
    		for(auto node: adj[source]){
    			if(node != parent){
    				dfs(node, source, dist + 1);
    			}
    		}
    	}
    }; dfs(1, -1, 0);

    int ans = 0;
    for(int i = 1; i <= n; i++){
    	ans = max(ans, capture[i]);
    }

    cout << ans << "\n";

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