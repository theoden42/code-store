
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 2, vector<int>(6, 0));

    dp[1][0] = 21;
    dp[1][1] = 5;

    dp[2][0] = 441;
    dp[2][1] = 215;
    dp[2][2] = 20;

    for(int i = 3; i <= n; i++){
    	dp[i][0] = (dp[i - 1][0] * 21) % MOD;
    	dp[i][1] = (((dp[i - 1][0] * 5)) % MOD + (dp[i - 1][1]) % MOD) % MOD;
    	dp[i][2] = (((dp[i - 1][1] * 4)) % MOD + (dp[i - 1][2]) % MOD) % MOD;
    	dp[i][3] = (((dp[i - 1][2] * 3)) % MOD + (dp[i - 1][3]) % MOD) % MOD;	
       	dp[i][4] = (((dp[i - 1][3] * 2)) % MOD + (dp[i - 1][4]) % MOD) % MOD;
       	dp[i][5] = (((dp[i - 1][4] * 1)) % MOD + (dp[i - 1][5]) % MOD) % MOD;
    }


    debug(dp[2]);

    ll ans = (dp[n][0] + dp[n][1] + dp[n][2] + dp[n][3] + dp[n][4] + dp[n][5]) % MOD;
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