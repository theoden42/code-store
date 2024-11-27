

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
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> edges(m);
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	edges[i] = {u, v};
    }

    vector<int> w(n + 1), a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    for(auto [a, b]: edges){
    	if(w[a] < w[b]){
    		swap(a, b);
    	}
    	adj[a].push_back(b);
    }

    vector<int> vals(n + 1, -1);

  	function<int(int)> dfs = [&](int source){
  		if(vals[source] != -1)
  			return vals[source];

  		int sz = adj[source].size();
  		int wt = w[source];

  		vector<vector<int>> dp(sz + 1, vector<int> (wt + 1, 0));

  		for(int i = 0; i < sz; i++){
  			int child = adj[source][i];
  			for(int j = 0; j <= wt; j++){
  				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
  				int v = j + w[child];
  				if(v < wt){
  					dp[i + 1][v] = dp[i][j] + dfs(child);
  				}
  			}
  		}

  		int mx = 1;
  		for(int i = 0; i <= wt; i++){
  			mx = max(mx, 1 + dp[sz][i]);
  		}

  		return vals[source] = mx;
  	};

  	for(int i = 1; i <= n; i++){
  		dfs(i);
  	}


  	int ans = 0;
  	for(int i = 1; i <= n; i++){
  		ans += (a[i] * vals[i]);
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