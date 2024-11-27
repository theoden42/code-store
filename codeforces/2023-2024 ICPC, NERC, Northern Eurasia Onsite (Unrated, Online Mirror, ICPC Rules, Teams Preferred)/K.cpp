

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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += 1 - (a[i] & 1);
	}
	int ans = 0;
	ans += binpow(2, cnt) - 1 + MOD;
	ans %= MOD;
	ans -= cnt;
	ans += MOD;
	ans %= MOD;
	ans -= (cnt * (cnt - 1)) / 2;
	ans += MOD;
	ans %= MOD;

	// debug(ans);

	for(int i = 0; i < 3; i++){
		vector<vector<int>> dp(n + 1, vector<int>(3, 0));
		dp[0][2] = 1;
		for(int j = 1; j <= n; j++){
			dp[j][0] = dp[j - 1][0];
			dp[j][1] = dp[j - 1][1];
			dp[j][2] = dp[j - 1][2];
			if(a[j - 1] & 1){
				for(int k = 0; k < 3; k++) if(k != i){
					dp[j][k] += dp[j - 1][(k + 2) % 3];
					dp[j][k] %= MOD;
				} 
			} else {
				dp[j][i] += dp[j - 1][(i + 2) % 3];
				dp[j][i] %= MOD;
			}
		}
		// debug(dp);
		ans += dp[n][0];
		ans %= MOD;
		ans += dp[n][1];
		ans %= MOD;
		ans += dp[n][2];
		ans %= MOD;

		ans -= 1;
		ans += MOD;
		ans %= MOD;
		if(i == 0){
			ans -= cnt;
			ans += MOD;
			ans %= MOD;
		} else {
			ans -= (n - cnt);
			ans += MOD;
			ans %= MOD;
		}
		int odd = 0, even = 0;
		for(int j = n - 1; j >= 0; j--){
			if(i == 0 && !(a[j] & 1)){
				ans -= odd;
				ans += MOD;
				ans %= MOD;
			}
			if(i != 0 && (a[j] & 1)){
				if(i == 1){
					ans -= even;
					ans += MOD;
					ans %= MOD;
				} else {
					ans -= odd;
					ans += MOD;
					ans %= MOD;
				}
			} 
			odd += (a[j] & 1);
			even += 1 - (a[j] & 1);
		}
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