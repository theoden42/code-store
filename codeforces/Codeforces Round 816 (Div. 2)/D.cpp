

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

void solve() {
    int n, q;
    cin >> n >> q;
    // debug(n, q);
    vector<int> ans(n + 1, 0);
    vector<vector<pair<int,int>>> adj(n + 1);
    map<pair<int,int>, int> mp;
    vector<int> cant(n + 1, (1 << 30) - 1);

    for(int k = 1; k <= q; k++){
    	int i, j, x;
    	cin >> i >> j >> x;

        if(mp.find({i, j}) != mp.end())continue;

        if(i == j){
            ans[i] = x;
        }
        else{
            adj[min(i, j)].push_back({max(i, j), x});
            mp[{min(i, j), max(i, j)}] = 1;
        }
    	cant[i] &= (x);
    	cant[j] &= (x);

    }

    // debug(cant);

    for(int i = 1; i <= n; i++){
        sort(all(adj[i]));
    }

    vector<int> vis(n + 1);

    function<void(int)> dfs = 
    [&](int source){
    	for(auto y: adj[source]){
    		int val = y.second;
    		for(int i = 30; i >= 0; i--){
    			if(val >> i & 1){
    				if((ans[source] >> i & 1) || (ans[y.first] >> i & 1)) continue;
    				else if(!(cant[y.first] >> i & 1)){
    					ans[source] |= (1 << i);
    				}
    			}

    		}
    	}

        for(auto y : adj[source]){
            int val = y.second;
            for(int i = 30; i >= 0; i--){
                if(val >> i & 1){
                    if(ans[source] >> i & 1 || ans[y.first] >> i & 1) continue;
                    else{
                        ans[y.first] |= (1 << i);
                    }
                }
            }
        }
    };	

    for(int i = 1; i <= n; i++){
    	if(vis[i])continue;
    	dfs(i);
    }

    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " ";
    }
    cout << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}