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
 
// vector<vector<ll>> dp(501, vector<ll>(3e5 + 1, -1));
 
// ll findsum(ll n, ll sum1){
//     if(sum1 > (n * (n + 1)) / 2){
//         dp[n][sum1] = 0;
//         return 0;
//     }
//     if(n == 1){
//         dp[n][sum1] = 1;
//         return 1;
//     }
//     if(sum1 >= n)
//         dp[n][sum1] = (findsum(n - 1, sum1) + findsum(n - 1, sum1 - n)) % MOD;
//     else{
//         dp[n][sum1] = findsum(n - 1, sum1) % MOD;
//     }
//     return dp[n][sum1];


// }

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
    ll n;
    cin >> n;   
    vector<vector<ll>> dp(2, vector<ll>((n * (n + 1)) / 2 + 1, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;

    for(ll i = 2; i <= n; i++){
        for(int j = 1; j <= (1ll * n * (n + 1)) / 2; j++){
                dp[1][j] = 0;
        }
        for(ll j = 1; j <= (1ll * n * (n + 1)) / 2; j++){
            dp[1][0] = 1;
            if(j >= i){
                dp[1][j] = (dp[1][j] + (dp[0][j] + dp[0][j - i]) % MOD) % MOD;
            }
            else{
                dp[1][j] = (dp[1][j] + dp[0][j]) % MOD;
            }
        }
        for(int j = 0; j <= (1ll * n * (n + 1)) / 2; j++){
            dp[0][j] = dp[1][j];
        }
    }

    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= i * i; j++){
    //         debug(i, j, dp[i][j]);
    //     }
    // }
    ll x = (n * (n + 1)) / 2;
    if(x % 2 != 0){
        cout << 0 << "\n";
        return;
    }
    cout << (dp[1][x / 2] * modinverse(2, MOD)) % MOD<< "\n";

}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}