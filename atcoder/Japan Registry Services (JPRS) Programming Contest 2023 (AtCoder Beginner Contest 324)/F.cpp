

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
#define double long double

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<vector<int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, b, c;
    	cin >> u >> v >> b >> c;
    	adj[u].push_back({v, b, c});
    }

    auto check = [&](double mid)->bool{
    	vector<double> dp(n + 1, 1e15);
    	dp[1] = 0;
    	for(int i = 1; i <= n; i++){
    		for(auto x: adj[i]){
    			int node = x[0];
    			int b = x[1];
    			int c = x[2];
    			dp[node] = min(dp[node], dp[i] + mid * c - b);
    		}
    	}

    	return (dp[n] <= 0);
    };


    double low = 0;
   	double high = 1e4 + 10;
    double ans = 0;
    for(int i = 1; i <= 64; i++){
    	double mid = (low + high) / 2.0;
    	if(check(mid)){
    		ans = max(ans, mid);
    		low = mid;
    	} else {
    		high = mid;
    	}
    }

    cout << setprecision(20) << ans << "\n";
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