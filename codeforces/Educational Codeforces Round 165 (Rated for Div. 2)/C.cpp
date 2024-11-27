

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e18));
    for(int i = 0; i <= k; i++){
    	dp[0][i] = 0;
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j <= k; j++){
    		dp[i][j] = min(dp[i][j], a[i - 1] + dp[i - 1][j]);
    		int mn = a[i - 1];
    		for(int l = i - 1; l > 0 && j + l >= i; l--){
    			mn = min(mn, a[l - 1]);
    			int len = i - l + 1;
    			dp[i][j] = min(dp[i][j], mn * len + dp[l - 1][j + l - i]);
    		}
    	}
    	// debug(dp[i]);
    }
    int ans = 1e18;
    for(int i = 0; i <= k; i++){
    	ans = min(ans, dp[n][i]);
    }
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