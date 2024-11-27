

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


struct LCA{
	/* struct used to implement Binary Lifting, 
	   can be modified to include various queries
	   be careful while passing in the root as 0 or 1
	*/
	int n, l;
	int timer;
	vector<vector<int>> adj;
	vector<vector<int>> up;
	vector<int> time_in, time_out;

	void dfsbuild(int v, int p){
		time_in[v] = ++timer;
		up[v][0] = p;
		for(int i = 1; i <= l; i++){
			int temp = up[v][i - 1];
			if(temp == -1)
				up[v][i] = -1;
			else
				up[v][i] = up[temp][i - 1];
		}

		for(int u: adj[v]){
			if(u != p)	
				dfsbuild(u, v);
		}
		time_out[v] = ++timer;
	}

	bool is_ancestor(int u, int v){
		return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
	}

	void init(int root, vector<vector<int>>& tree){
		n = tree.size();
		timer = 0
		adj.resize(n);
		adj = tree;
		l = ceil(log2(n));
		up.assign(n, vector<int>(l + 1, -1));
		time_in.resize(n);
		time_out.resize(n);
		dfsbuild(root, -1);
	}

	int lift(int u, int k){
		int nd = u;
		for(int i = l; i >= 0; i--){
			if(nd == -1)return -1;

			if(k >> i & 1)
				nd = up[nd][i];
		}
		return nd;
	}

	int lca(int u, int v){
		if(is_ancestor(u, v)){
			return u;
		}
		if(is_ancestor(u, v)){
			return v;
		}
		for(int i = l; i >= 0; i--){
			if(!is_ancestor(up[u][i], v))
				u = up[u][i];
		}
		return up[u][0];
	}

};


void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
    	int p;
    	cin >> p;
    	adj[p].push_back(i);
    	adj[i].push_back(p);
    }

    LCA lt;
    lt.init(1, adj);
    for(int i = 1; i <= q; i++){
    	int u, v;
    	cin >> u >> v;
    	int ans = lt.lift(u, v);
    	cout << ans << "\n";
    }
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