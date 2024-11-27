


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
    map<pair<int,int>, int> mp;
    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++){
    	int a, b, d;
    	cin >> a >> b >> d;
    	adj[a].push_back({b, d});
    	adj[b].push_back({a, -d});
    }

    vector<int> vis(n + 1);
	vector<int> distance(n + 1, INF);

	int flag = 1;

	function<void(int, int)> dfs 
	=[&](int source, int dist){
		if(distance[source] != INF && dist != distance[source]){
			flag = 0;
			return;	
		}
		distance[source] = dist;
		if(vis[source])
			return;

		vis[source] = 1;

		for(auto [node, weight]: adj[source]){
			dfs(node, dist + weight);	
		}
		return;
	};


	for(int i = 1; i <= n; i++){
		if(vis[i])
			continue;

		distance[i] = 0;
		dfs(i, 0);	
	}

	if(flag){
		cout << "YES\n";
	}else{
		cout << "NO\n";
	}

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