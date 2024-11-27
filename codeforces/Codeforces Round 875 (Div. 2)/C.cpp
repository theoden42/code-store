

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


int dfs(int source, int pnt, vector<vector<int>>& adj, int edgenum, map<int,int>& parent, map<pair<int,int>, int>& mp){

	int mx = 0;
	for(auto x: adj[source]){
		if(x == pnt)continue;

		int ed = mp[{source, x}];
		parent[ed] = edgenum;

		if(ed > edgenum){
			mx = max(mx, dfs(x, source, adj, ed, parent, mp));
		}
		else{
			mx = max(mx, 1 + dfs(x, source, adj, ed, parent, mp));
		}
	}

	return mx;
}

void solve() {
	int n;
	cin >> n;

	vector<vector<int>> adj(n + 1);
	map<pair<int,int>, int> mp;


	for(int i = 1; i <= n - 1; i++){
		int u, v;
		cin >> u >> v;
		mp[{u, v}] = i;
		mp[{v, u}] = i;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	map<int,int> parent;

	int ans = dfs(1, -1, adj, 0, parent, mp);
	ans++;

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