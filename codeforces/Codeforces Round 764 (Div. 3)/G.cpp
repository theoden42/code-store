

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
		if(x == parent[x])
			return x;
		return parent[x] = getparent(parent[x]);
	}

	void unite(int a, int b){
		a = getparent(a);
		b = getparent(b);

		if(a == b)
			return;

		if(sz[a] < sz[b])
			swap(a, b);

		parent[b] = a;
		sz[a] += sz[b];
	}

	int comp_size(int vert){
		int p = getparent(vert);
		return sz[p];
	}

};

void solve() {
    int n, m;
    cin >> n >> m;
   	vector<vector<int>> edges;

    for(int i = 0; i < m; i++){
    	int v, u, w;
    	cin >> v >> u >> w;
    	edges.push_back({v, u, w});
    }

    function<int(vector<vector<int>>&)> check 
    = [&](vector<vector<int>>& ed){
    	dsu d;
    	d.init(n);
    	for(auto& it : ed){
    		int u = it[0] - 1;
    		int v = it[1] - 1;
			d.unite(u, v);
    	}

    	int sz = d.comp_size(0);
    	return (sz == n);
    };	

    for(int i = 31; i >= 0; i--){
    	vector<vector<int>> new_edge;
    	for(auto& it: edges){
    		if(it[2] >> i & 1)
    			continue;
    		new_edge.push_back(it);
    	}

    	if(check(new_edge)){
    		edges = new_edge;
    	}
    }

	int ans = 0;
	for(auto& it: edges){
		ans |= it[2];
	}
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