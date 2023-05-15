

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



bool dfs(int source, vector<int>& vis, vector<int>& cn, vector<vector<int>>& adj, vector<int>& cycle){
	vis[source] = 1;
	cn[source] = 1; 
	for(auto &x: adj[source]){
		if(cn[x] == 1){
			cycle[x] = 1;
			return true;
		}
		if(!vis[x]){
			if(dfs(x, vis, cn, adj, cycle)){
				cycle[source] = 1;
			}

		}
	}
	return false;
}




void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> g(n + 1);
    for(int i = 1; i <= n; i++){
    	int x = a[i];
    	if(x != i){
    		g[i].push_back(x);
    	}	

    }

    vector<int> vis(n + 1, 0);
    vector<int> cycle(n + 1, 0);
    vector<int> cn(n + 1, 0);

    for(int i = 1; i <= n; i++){

    	for(int j = 1; j <= n; j++){
    		cn[i] = 0;
    	}
    	dfs(i, vis, cn, adj, cycle);
    }

    for(int i = 1; i <= n; i++){
    	if(a[i] == i || cycle[i]){
    		 count++;
    	}
    }

    cout << count << "\n";

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