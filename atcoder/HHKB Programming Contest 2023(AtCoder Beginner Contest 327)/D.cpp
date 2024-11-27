

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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for(int i = 0; i < m; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	adj[a[i]].push_back(b[i]);
    	adj[b[i]].push_back(a[i]);
    }

    // debug(adj, a, b);

    vector<int> vis(n + 1);
    vector<int> vals(n + 1);
    function<int(int,int)> dfs = [&](int source, int values){
    	vals[source] = values;
    	vis[source] = 1;
    	int f = 1;
    	for(auto x: adj[source]){
    		if(!vis[x]){
    			f &= dfs(x, 1 - values);
    		} else if(vals[x] != 1 - values){
    			f = 0;
    		}
    	}
    	return f;
    };
    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		if(!dfs(i, 0)){
    			cout << "No\n";
    			return;
    		}
    	}
    }

    cout << "Yes\n";
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