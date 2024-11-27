#include<bits/stdc++.h>
#include<debug.h>

using namespace std;

#define ll long long
const int MAX_N = 1e6 + 5;
const int MOD = 1e9 + 7;


struct LCA{
	/* struct used to implement Binary Lifting, 
	   can be modified to include various queries
	   be careful while passing in the root as 0 or 1
	*/
	int n, l;
	int timer = 0;	
	vector<vector<int>> adj;
	vector<vector<int>> up;
	vector<int> time_in, time_out;

	void dfsbuild(int v, int p){
		time_in[v] = timer++;
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
		time_out[v] = timer++;
	}

	bool is_ancestor(int u, int v){
		return time_in[u] <= time_in[v] && time_out[u] >= time_out[v];
	}

	void init(int root, vector<vector<int>>& tree){
		n = tree.size();
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
			if(up[u][i] != -1 && !is_ancestor(up[u][i], v))
				u = up[u][i];
		}
		return up[u][0];
	}

};

int binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}


int main(){
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        debug(adj);

        LCA lc;
        lc.init(0, adj);
        vector<int> dis(n);
        function<void(int,int)> dfs = [&](int source, int parent){
            for(auto x: adj[source]){
                if(x == parent)
                    continue;
                dis[x] = dis[source] + 1;
                dfs(x, source);
            }
        };
        dis[0] = 0;
        dfs(0, -1);

        for(int i = 1; i <= q; i++){
            int u, v;
            cin >> u >> v;
            int l = lc.lca(u, v);
            int d = dis[v] + dis[u] - 2 * dis[l];
            int ans = binpow(2, d);
            cout << ans << "\n";
        }
    }
}
        
