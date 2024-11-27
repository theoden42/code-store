

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


void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 2);
    vector<int> values(n + 2);
    vector<vector<int>> queries;

    int num = 2;
    values[1] = 1;

    for(int i = 1; i <= n; i++){
    	char ch;
    	cin >> ch;
    	if(ch == '+'){
    		int v, x;
	    	cin >> v >> x;
            adj[v].push_back(num);
            adj[num].push_back(v);
            values[num] = x;
            num++;
    	}	
    	else{
    		int u, v, k;
    		cin >> u >> v >> k;
            queries.push_back({u, v, k});
    	}
    }

    vector<int> maxvals(n + 2, 0);
    vector<int> minvals(n + 2, 0);
    vector<int> ansmin(n + 2, 0);
    vector<int> ansmax(n + 2, 0);

    function<void(int, int)> dfsmin = 
    [&](int source, int parent){
        for(auto x: adj[source]){
            if(x == parent){
                continue;
            }
            minvals[x] = min({minvals[source] + values[x], 0ll, values[x]});
            ansmin[x] = min(minvals[x], ansmin[source]);
            dfsmin(x, source);
        }
    };

    function<void(int, int)> dfsmax = 
    [&](int source, int parent){
        for(auto x: adj[source]){
            if(x == parent){
                continue;
            }
            maxvals[x] = max({maxvals[source] + values[x], 0ll, values[x]});
            ansmax[x] = max(maxvals[x], ansmax[source]);
            dfsmax(x, source);
        }
    };


    maxvals[1] = max(0ll, values[1]);
    minvals[1] = min(0ll, values[1]);
    ansmax[1] = max(0ll, values[1]);
    ansmin[1] = min(0ll, values[1]);
    dfsmin(1, -1);
    dfsmax(1, -1);

    // debug(maxvals, minvals, ansmax, ansmin);

    for(auto q : queries){
        int u = q[0];
        int v = q[1];
        int k = q[2];
        int mn = ansmin[v];
        int mx = ansmax[v];
        if(k >= mn && k <= mx){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
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