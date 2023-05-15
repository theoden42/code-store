

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

int dfs(int source, vector<vector<int>>& adj, int parent, vector<int>& depth){

	int mx = 0;
	vector<int> temp;

	for(auto& x: adj[source]){
		if(x != parent){
			dfs(x, adj, source, depth);
			temp.push_back(depth[x]);
		}
	}
	
	sort(temp.rbegin(), temp.rend());

	for(int i = 0; i < temp.size(); i++){
		int x = temp[i] + i + 1;
		mx = max(mx, x);
	}

	depth[source] = mx;
	return depth[source];
}


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

	vector<int> depth(n + 1);
	depth[1] = dfs(1, adj, -1, depth);

	cout << depth[1] << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}