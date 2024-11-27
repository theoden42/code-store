

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
	vector<int> sz;

	void init(int n){
		parent.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)return 0;

		if(sz[a] < sz[b])
			swap(a, b);

		parent[b] = a;
		sz[a] += sz[b];
		return 1;
	}

};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	edges[i] = {w, u, v};
    }

    sort(all(edges));
    reverse(all(edges));

    dsu d;
    d.init(n + 1);
    vector<vector<int>> adj(n + 1);

    int ind = 0;
    int count = 0;
    for(auto v: edges){
    	if(d.getparent(v[1]) == d.getparent(v[2])){
    		ind = count;
    	} else {
    		adj[v[1]].push_back(v[2]);
    		adj[v[2]].push_back(v[1]);
    		d.unite(v[1], v[2]);
    	}
    	count += 1;
    }

   	int a = edges[ind][1];
   	int b = edges[ind][2];

   	vector<int> ans;
   	vector<int> temp;

   	function<void(int, vector<int>&, int)> dfs
   	= [&](int source, vector<int> &cur, int parent = -1){
   		if(source == b){
   			ans = cur;
   			return;
   		}
   		for(auto x: adj[source]){
   			if(x == parent)
   				continue;
   			cur.push_back(x);
   			dfs(x, cur, source);
   			cur.pop_back();
   		}
   	}; 


   	temp.push_back(a);
   	dfs(a, temp, -1);

   	cout << edges[ind][0] << " " << ans.size() << "\n";

   	for(auto a: ans){
   		cout << a << " ";
   	}
   	cout << "\n";

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