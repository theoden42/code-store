
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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



ll findnumberofsequence(int k, int n, vector<vector<ll>>& dp){
    if(dp[n][k] != -1){
        return dp[n][k];
    }
    if(k == 1){
        dp[n][k] = 1;
        return 1;
    }
    if(n == 1){
        dp[n][k] = 1;
        return 1;
    }
    ll count = 0;
    for(int i = 1; i * i <= n; i++){
        if(n % i != 0)
            continue;
        count = (count + findnumberofsequence(k - 1, i, dp)) % MOD;
        count = (count + findnumberofsequence(k - 1, n / i, dp)) % MOD;
    }
    dp[n][k] = count;
    return count;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<ll>> dp(k + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= n; j++){
            for(int l = 1; l * l <= j; l++){
                if(j % l == 0){
                    dp[i][j] = (dp[i][j] + dp[i - 1][l]) % MOD;
                    if((j / l) != l )
                    dp[i][j] = (dp[i][j] + dp[i - 1][j / l]) % MOD;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans = (ans + dp[k][i]) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}