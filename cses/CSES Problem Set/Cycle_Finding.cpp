

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
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++){
    	int u, v, c;
    	cin >> u >> v >> c;
    	edges.push_back({u, v, c});
    }

    vector<int> dis(n + 1);
    vector<int> p(n + 1);
    dis[1] = 0;
    int x;
    for(int i = 0; i < n; i++){
    	x = -1;
    	for(auto e: edges){
    		if(dis[e[0]] != INF){
    			if(dis[e[1]] > dis[e[0]] + e[2]){
    				dis[e[1]] = max(-INF, dis[e[0]] + e[2]);
    				p[e[1]] = e[0];
    				x = e[1];
    			}
    		}
    	}
    }

    if(x == -1){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";
    int y = x;
    for(int i = 0; i < n; i++){
    	y = p[y];
    }
    vector<int> path;
    for(int cur = y; ; cur = p[cur]){
    	path.push_back(cur);
    	if(cur == y && path.size() > 1){
    		break;
    	}
    }
    reverse(all(path));
    for(auto p: path){
    	cout << p << " ";
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