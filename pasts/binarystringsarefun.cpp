
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
const ll MOD = 998244353;
const ll INF = 1e9;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> dp(n + 1, 0);
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
    	if(s[i - 1] == s[i - 2]){
    		dp[i] = (2ll * dp[i - 1]) % MOD;
    	}
    	else{
    		dp[i] = 1;
    	}
    }	
    debug(dp);

    ll sum = 0;
    for(int i = 1; i <= n; i++){
    	sum = (sum + dp[i]) % MOD;
    }
    cout << sum << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}