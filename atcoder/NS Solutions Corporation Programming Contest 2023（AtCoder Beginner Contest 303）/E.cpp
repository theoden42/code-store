

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

   	vector<int> ans;
   	function<void(int, int, int)> dfs 
   	= [&](int source, int parent, int flag){
        // debug(source, flag);
   		if(flag < 2) {
   			int node;
	   		for(auto x: adj[source]){
	   			if(x == parent)
	   				continue;
	   			node = x;
	   			break;
	   		}
	   		dfs(node, source, flag + 1);
   		} else {
   			int sz = adj[source].size();
   			ans.push_back(sz);
   			for(auto x: adj[source]){
                if(x == parent)
                    continue;
   				if(adj[x].size() > 1){
                    dfs(x, source, 0);
   				}
   			}
   		}
   	};

   	for(int i = 1; i <= n; i++){
   		if(adj[i].size() == 1){
            // debug(i);
   			dfs(i, -1, 1);
   			break;
   		}
   	}
   	sort(all(ans));
   	for(auto a: ans){
   		cout << a << " ";
   	}
   	cout << "\n";
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