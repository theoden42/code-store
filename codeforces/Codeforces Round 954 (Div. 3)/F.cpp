

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> vis(n + 1), tin(n + 1), low(n + 1);
    multiset<pair<int,int>> bridge;
    function<void(int, int)> dfs = [&](int v, int p = -1){
    	vis[v] = true;
    	tin[v] = low[v] = timer++;
    	bool parent_skipped = false;
    	for(int to: adj[v]){
    		if(to == p && !parent_skipped){
    			parent_skipped = true;
    			continue;
    		}
    		if(vis[to]){
    			low[v] = min(low[v], tin[to]);
    		} else {
    			dfs(to, v);
    			low[v] = min(low[v], low[to]);
    			if(low[to] > tin[v]){
    				bridge.insert({min(to, v), max(to, v)});
    			}

    		}
    	}
    }; dfs(1, -1);

    multiset<int> nvis;
    int mx = 0;
    function<void(int)> search = [&](int source){
    	nvis.insert(source);
    	for(auto x: adj[source]) if(nvis.find(x) == nvis.end()){
    		int sz = nvis.size();
    		search(x);
    		int sz2 = nvis.size();
    		if(bridge.find({min(source, x), max(source, x)}) != bridge.end()){
    			int val = sz2 - sz;
    			int rem = val * (n - val);
    			mx = max(mx, rem);
    		}
    	}
    };search(1);

    int ans = (n * (n - 1)) / 2 - mx;
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