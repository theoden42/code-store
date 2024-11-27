

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

struct dsu{
	vector<int> parent;
	vector<int> size;

	void init(int n){
		parent.resize(n);
		size.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			size[i] = 1;
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)
			return 0;

		if(size[a] < size[b])
			swap(a, b);

		parent[b] = a;
		size[a] += size[b];
		return 1;
	}

};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<pair<int,int>> edges;
	vector<vector<int>> adj(n + 1);

	dsu d;
	d.init(n + 1);

	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		edges.push_back({u, v});
		if(a[u] == a[v]){
			d.unite(u, v);
		}
	}

	vector<int> label(n + 1);
	for(int i = 1; i <= n; i++){
		label[i] = d.getparent(i);
	}

	for(auto [u, v]: edges){
		int l = label[u];
		int m = label[v];
		adj[l].push_back(m);
		adj[m].push_back(l);
	}

	vector<int> dp(n + 1, -1);
	dp[label[n]] = 1;
	function<int(int)> dfs = [&](int source){
		if(dp[source] != -1)
			return dp[source];
		int mx = 0;
		for(auto x: adj[source]){
			if(a[x] > a[source]){
				int v = dfs(x);
				if(v != 0)
					mx = max(mx, 1 + v);
			}
		}
		return dp[source] = mx;;
	}; dfs(label[1]);


	cout << dp[label[1]] << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}