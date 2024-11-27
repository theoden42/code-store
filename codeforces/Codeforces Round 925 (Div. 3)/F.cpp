

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(k);
    for(int i = 0; i < k; i++){
    	for(int j = 0; j < n; j++){
    		int x;
    		cin >> x;
    		v[i].push_back(x);	
    	}
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < k; i++){
    	for(int j = 2; j < n; j++){
    		adj[v[i][j - 1]].push_back(v[i][j]);
    	}
    }

    // debug(adj);

    vector<int> vis(n + 1), curr(n + 1);
    function<int(int)> dfs = [&](int source){
    	// debug(source);
    	vis[source] = 1;
    	curr[source] = 1;
    	for(auto x: adj[source]){
    		if(curr[x])
    			return true;
    		if(!vis[x] && dfs(x))
    			return true;
    	}
    	curr[source] = 0;
    	return false;
    };

    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		if(dfs(i)){
    			cout << "NO\n";
    			return;
    		}
    	}
    }

    cout << "YES\n";

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