

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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> dp(n + 1, -1);
    int ans = 0;
    function<int(int,int)> dfs = [&](int source, int parent){
    	int p = 1;
    	if(dp[source] != -1)
    		return dp[source];
    	for(auto x: adj[source]){
    		if(x == parent)
    			continue;
    		p *= dfs(x, source);
    		p %= MOD;
    	}
    	p += 1;
    	p %= MOD;
    	ans += p;
    	ans %= MOD;
    	return dp[source] = p;
    };

    dfs(1, -1);

    ans -= (n - 1);
    ans += MOD;
    ans %= MOD;

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}