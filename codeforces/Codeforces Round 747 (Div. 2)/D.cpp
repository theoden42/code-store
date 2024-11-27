

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + m + 2);
    int dummy = n + 1;
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	string s;
    	cin >> s;
    	if(s == "imposter"){ 
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	} else {
    		adj[u].push_back(dummy);
    		adj[dummy].push_back(u);
    		adj[v].push_back(dummy);
    		adj[dummy].push_back(v);
    		dummy += 1;
    	}
    }

    vector<int> color(n + m + 2);
    vector<int> vis(n + m + 2);

   	function<int(int, int, vector<int>& comp)> dfs = [&](int source, int cur_color, vector<int>& comp){
   		if(vis[source] && color[source] != cur_color){
   			return 0;
   		} else if(vis[source]){
   			return 1;
   		}
   		comp.push_back(source);
   		vis[source] = 1;
   		color[source] = cur_color;
   		int ans = 1;
   		for(auto x: adj[source]){
   			ans &= dfs(x, 1 - cur_color, comp);
   		}	
   		return ans;
   	};

   	int ans = 0;

    for(int i = 1; i < n + m + 2; i++){
    	if(!vis[i]){
    		vector<int> comp;
    		int c0 = 0, c1 = 0;
    		if(!dfs(i, 0, comp)){
    			cout << "-1\n";
    			return;
    		}
    		for(auto ele: comp){
    			if(ele > n)
    				continue;
    			if(color[ele] == 0){
    				c0++;
    			} else {
    				c1++;
    			}
    		}
    		ans += max(c0, c1);
    	}	
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