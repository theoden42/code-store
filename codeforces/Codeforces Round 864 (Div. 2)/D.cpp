

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

vector<vector<int>> adj;
vector<int> parent;
vector<multiset<pair<int,int>>> child;
vector<int> sz;
vector<int> importance;

int szdfs(int source, int p = -1){
	sz[source] = 1;
	for(auto x: adj[source]){
		if(x != p){
			sz[source] += szdfs(x, source);
		}
	}	
	return sz[source];
}

int dfsinit(int source, int p = -1){
	for(auto x: adj[source]){
		if(x != p){
			child[source].insert({sz[x], -x});
			parent[x] = source;
			importance[source] += dfsinit(x, source);
		}
	}
	return importance[source];
}


void solve() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    parent.resize(n + 1);
    child.resize(n + 1);
    sz.resize(n + 1);
    importance.resize(n + 1);

    for(int i = 1; i <= n; ++i){
    	cin >> importance[i];
    }


    for(int i = 1; i <= n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    szdfs(1);	
    dfsinit(1);

    for(int i = 1; i <= m; i++){
    	int t, x;
    	cin >> t >> x;
    	if(t == 1){
    		cout << importance[x] << "\n";
    	}
    	else{
    		if(child[x].size() == 0)continue;

    		auto it = --child[x].end();
    		int c = -1 * it->second;
    		int p = parent[x];

    		int tsz = sz[x] - sz[c];
    		int tim = importance[x] - importance[c];

    		child[p].erase({sz[x], -x});	
    		child[x].erase({sz[c], -c});

    		sz[c] += tsz;
    		sz[x] = tsz;
    		importance[c] += tim;
    		importance[x] = tim;

    		child[p].insert({sz[c], -c});
    		child[c].insert({sz[x], -x});
    		parent[c] = p;
    		parent[x] = c;
    	}
    }
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