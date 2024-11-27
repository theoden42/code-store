

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
const ll INF = 1e10;

#define int long long

bool check(int val, vector<vector<int>>& edges, vector<int>& a, int k){
	int count = 0;
	int n = a.size();

	// debug(val, st);

	vector<vector<int>> adj(n);	
	for(auto e: edges){
		int x = e[0];
		int y = e[1];
		if(a[x] > val || a[y] > val){
			continue;
		}
		adj[e[0]].push_back(e[1]);
	}

	// debug(adj);

	vector<int> vis(n, 0);
	vector<int> pathvis(n, 0);
	for(int i = 0; i < n; i++){
		if(a[i] > val){
			vis[i] = 1;
			pathvis[i] = 1;
		}
	}

	function<int(int)> dfscycle = [&](int source){
		vis[source] = 1;
		pathvis[source] = 1;
		for(auto x: adj[source]){
			if(pathvis[x])return true;
			else if(!vis[x]){
				if(dfscycle(x))
					return true;
			}
		}
		pathvis[source] = 0;
		return false;
	};

	for(int i = 0; i < n; i++){
		if(vis[i])continue;

		if(dfscycle(i))return true;
	}

	vector<int> dp(n);
	for(int i = 0; i < n; i++){
		vis[i] = 0;
		if(a[i] > val){
			dp[i] = 0;
			vis[i] = 1;	
		}
		else{
			dp[i] = 1;
		}
	}

	function<int(int)> dfsdp = [&](int source){
		if(vis[source])return dp[source];
		vis[source] = 1;
		int mx = 1;
		for(auto x: adj[source]){
			mx = max(mx, 1 + dfsdp(x));
		}
		return dp[source] = mx;
	};

	for(int i = 0; i < n; i++){
		if(!vis[i]){
			dfsdp(i);
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = max(ans, dp[i]);
	}

	if(ans >= k)return true;
	else return false;

}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;	
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];	
    }
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	edges[i] = {u, v};	
    }


    int low = 0;
    int high = INF;
    int ans = INF;	

    while(low <= high){
    	int mid = (low + high) / 2;
    	if(check(mid, edges, a, k)){
    		high = mid - 1;
    		ans = mid;		
    	}
    	else{
    		low = mid + 1;	
    	}
    }

    if(ans == INF){
    	cout << "-1\n";
    	return;
    }
    cout << ans << "\n";

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