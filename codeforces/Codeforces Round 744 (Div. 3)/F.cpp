

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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n; i++){
    	adj[i].push_back((i + d) % n);
    }

    debug(adj);

    vector<int> vis(n);

    function<void(int, vector<int>&)> dfs 
    = [&](int source, vector<int>& comp) { 
    	debug(source);
    	if(vis[source])
    		return;
    	comp.push_back(a[source]);
    	vis[source] = 1;
    	dfs(adj[source][0], comp);
    };

    int ans = 0;
    for(int i = 0; i < n; i++){
    	if(vis[i]){
    		continue;
    	}
		vector<int> comp;
		dfs(i, comp);
    	int ind = -1;
    	for(int j = 0; j < comp.size(); j++){
    		if(comp[j] == 0){
    			ind = j;
    			break;
    		}
    	}
    	if(ind == -1){
    		cout << "-1\n";
    		return;
    	}
    	int count = 0;
    	int sz = comp.size();
    	int maxsz = 0;
    	int curr = (ind + 1) % sz;
    	while(curr != ind){
    		if(comp[curr] == 1){
    			count += 1;
    		} else{
    			maxsz = max(maxsz, count);
    			count = 0;
    		}
    		curr = (curr + 1) % sz;
    	}
    	maxsz = max(maxsz, count);
    	ans = max(ans, maxsz);
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