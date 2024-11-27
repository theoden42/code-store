

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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i] >> b[i];
    }
	vector dp(n + 1, vector<vector<int>>(n + 1, vector<int>(x + 1, 1e18)));
	dp[0][0][0] = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k <= x; k++){
				if(k + a[i] <= x){
					dp[i + 1][j + 1][k + a[i]] = min(dp[i + 1][j + 1][k + a[i]], b[i] + dp[i][j][k]);
				}
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
			}
		}
	}

	int ans = 0;
	for(int j = 1; j <= n; j++){
		for(int k = 0; k <= x; k++){
			if(dp[n][j - 1][k] <= y){
				ans = max(ans, j);
			}
		}
	}
	cout << ans << "\n";
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