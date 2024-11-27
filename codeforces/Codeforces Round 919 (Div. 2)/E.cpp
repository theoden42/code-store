

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
	int n, k;
	cin >> n >> k;
	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
	for(int i = 1; i <= k; i++){
		dp[0][i] = 1;
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= k; j++){
			for(int nxt = 1; nxt <= k && nxt + j <= k + 1 && nxt * j <= n - i; nxt += 1){
				int val = i + nxt * j;
				dp[val][nxt] += dp[i][j];
				dp[val][nxt] %= MOD;
			}
		}
	}
	int ans = 0;
	for(int nxt = 1; nxt <= k; nxt++){
		ans += dp[n][nxt];
		ans %= MOD;
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