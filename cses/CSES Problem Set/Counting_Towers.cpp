
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


long long dp[MAX_N + 5][2];

void preprocess(){
	dp[MAX_N + 1][0] = dp[MAX_N + 1][1] = 1;
	 for(int i = MAX_N; i >= 2; i--){
    	ll op1 = (dp[i + 1][0] + dp[i + 1][1])  % MOD;
    	ll op2 = (dp[i + 1][1]);
    	ll op3 = (dp[i + 1][0]);
    	ll op4 = (2 * dp[i + 1][0]) % MOD;
    	dp[i][0] = ((op1 + op3) % MOD + op4) % MOD;
    	dp[i][1] = (op2 + op1) % MOD;
    }

}


void solve() {
    int n;	
    cin >> n;  	
    cout << (dp[MAX_N - n + 2][0] + dp[MAX_N - n + 2][1]) % MOD << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;

    preprocess();
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}