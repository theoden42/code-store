

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
	const int INF = 1e15 + 7;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n + 1);
    vector<int> incycle(n + 1), vis(n + 1);

    for(int i = 0; i < m; i++){
    	int a, b, c;
    	cin >> a >> b >> c;
        adj[b].push_back(a);
    	edges.push_back({a, b, -c});
    }

    vector<int> d(n + 1, INF);
    d[1] = 0;
    for(int i = 0; i < n - 1; i++){
    	for(auto e: edges){
    		if(d[e[0]] != INF){
    			if(d[e[1]] > d[e[0]] + e[2]){
    				d[e[1]] = max(-INF, d[e[0]] + e[2]);
    			}
    		}
    	}
    }

    for(auto e: edges){
        if(d[e[0]] != INF){
            if(d[e[1]] > d[e[0]] + e[2]){
                incycle[e[1]] = 1;
                d[e[1]] = max(-INF, d[e[0]] + e[2]);
            }
        }
    }

    function<void(int)> dfs = [&](int source){
        vis[source] = 1;
        for(auto node: adj[source]){
            if(!vis[node])
                dfs(node);
        }
    }; dfs(n);

    for(int i = 1; i <= n; i++){
        if(incycle[i] && vis[i]){
            cout << "-1\n";
            return;
        }
    }

    int ans = -d[n];
    cout << ans << "\n";
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