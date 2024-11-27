

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
    int n, m, c;
    cin >> n >> m >> c;
    vector<pair<int,int>> vp(m);
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    	vp[i] = {u, v};
    }

    vector<int> sz(n + 1);
    function<void(int,int)> 
    dfs = [&](int src, int pnt=-1){
    	sz[src] = 1;
    	for(auto x: adj[src]) if (x != pnt) { 
    		dfs(x, src);
    		sz[src] += sz[x];
    	}	
    };

    dfs(1, -1);

    int mn = 1e18;
    for(int i = 1; i <= n; i++){
    	int x = sz[i];
    	int cst = x * x + (n - x) * (n - x);
    	mn = min(mn, cst);
    }
    cout << mn << "\n";
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