

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
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> dis(n);
    vector<int> dis2(n);

    function<void(int, int, int)> dfs = [&](int source, int parent, int d){
    	dis[source] = d;
    	for(auto x: adj[source]){
    		if(x == parent)continue;

    		dfs(x, source, d + 1);
    	}
    };
    function<void(int, int, int)> dfs2 = [&](int source, int parent, int d){
    	dis2[source] = d;
    	for(auto x: adj[source]){
    		if(x == parent)continue;

    		dfs2(x, source, d + 1);
    	}
    };
    dfs(0, -1, 0);
    int mx = 0;
    int mxnode = 0;
    for(int i = 0; i < n; i++){
    	if(dis[i] > mx){
    		mx = dis[i];
    		mxnode = i;
    	}
    }

    dfs(mxnode, -1, 0);
    int mxnode2 = 0;
    mx = 0;
    for(int i = 0; i < n; i++){
    	if(dis[i] > mx){
    		mx = dis[i];
    		mxnode2 = i;
    	}
    }

    dfs2(mxnode2, -1, 0);
    for(int i = 0; i < n; i++){
    	int ans = max(dis[i], dis2[i]);
    	cout << ans << " ";
    }
    cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}