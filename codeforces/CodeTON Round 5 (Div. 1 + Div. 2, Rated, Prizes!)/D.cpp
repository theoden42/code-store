

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
const ll INF = 1e11;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, y;
    	cin >> u >> v >> y;
    	adj[u].push_back({v, y});
    	adj[v].push_back({u, y});
    }

    vector<int> vis(n + 1);
    function<int(int)> canreach = [&](int source){
    	if(source == n)return 1;
    	vis[source] = 1;
    	for(auto [child, weight] : adj[source]){
    		if(!vis[child]){
    			if(canreach(child))return 1;
    		}
    	}

    	return 0;
    };

    if(!canreach(1)){
    	cout << "inf\n";
    	return;
    }

    vector<pair<string, int>> ans;

    vector<int> curr(n + 1, 0);
    vector<int> time(n + 1, 0);
    curr[1] = 1;
    time[1] = 0;

    int count = 1;

    while(!curr[n]){

    	int mn = INF;
    	for(int i = 1; i <= n; i++){
    		if(curr[i]){
    			for(auto [vert, mxtime]: adj[i]){
    				if(curr[vert])
    					continue;
    				int x = mxtime - time[i];	
    				mn = min(mn, x);
    			}
    		}
    	}

    	string x = "";
    	for(int i = 1; i <= n; i++){
    		if(curr[i]){
    			time[i] += mn;	
    			x += '1';
    		}
    		else{
    			x += '0';
    		}
    	}

    	ans.push_back({x, mn});

    	count = 0;
    	for(int i = 0; i <= n; i++){
    		if(curr[i]){
    			for(auto [vert, mxtime]: adj[i]){
    				if(curr[vert])
    					continue;
    				int x = mxtime - time[i];
    				if(x == 0){
    					curr[vert] = 1;

    				}
    			}
    		}
    	}
    }

    int totaltime = 0;
    for(auto [st, t]: ans){
        totaltime += t;
    }

    cout << totaltime << " " << ans.size() << "\n";
    for(auto [st, t]: ans){
    	cout << st << " " << t << "\n";
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