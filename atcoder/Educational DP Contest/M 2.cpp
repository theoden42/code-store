
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[105][100005];


void solve() {
	memset(dp, sizeof(dp), 0);
	int n, k;
	cin >> n >> k;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}

	dp[n][0] = 1;

	vector<int> pref(k + 1);
	pref[0] = dp[n][0];

	for(int i = 1; i <= k; i++){
		pref[i] = (pref[i - 1] + dp[n][i]) % MOD;
	}



	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j <= k; j++){
			int m = max(0ll, j - ele[i]);
			dp[i][j] = ((pref[j] - pref[m] + MOD) % MOD + dp[i + 1][m]) % MOD;
		}
		pref[0] = dp[i][0];
		for(int j = 1; j <= k; j++){
			pref[j] = (pref[j - 1] + dp[i][j]) % MOD;
		}
	}

	cout << dp[0][k] << "\n";

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