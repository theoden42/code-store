
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



// ll numberofvalues(int n, int m, int ind, int prev){
// 	if(ind == n)
// 		return 0;
// 	if(dp[ind][prev] != 0){
// 		return dp[ind][prev];
// 	}
// 	if(ele[ind] != 0){
// 		if(prev == -1){
// 			dp[ind][0] = numberofvalues(n, m, ind + 1, ele[0]) % MOD;
// 			return dp[ind][0];
// 		}
// 		if(abs(ele[ind] - prev) == 1){
// 			dp[ind][prev] = 0;
// 		}
// 		else{
// 			dp[ind][prev] = numberofvalues(n, m, ind + 1, ele[ind]) % MOD;
// 		}
// 		return dp[ind][prev];
// 	}
// 	else{
// 		if(prev == -1){
// 			for(int i = 1; i <= m; i++){
// 				dp[ind][prev] = (dp[ind][prev] + numberofvalues(n, m, ind + 1, i))%MOD; 
// 			}
// 		}
// 		else{
// 			if(prev - 1 >= 1){
// 				dp[ind][prev] = (dp[ind][prev] + numberofvalues(n, m, ind + 1, prev - 1))%MOD;
// 			}
// 			else if(prev + 1 <= m){
// 				dp[ind][prev] = (dp[ind][prev] + numberofvalues(n, m, ind + 1, prev + 1)) % MOD;
// 			}
// 		}
// 		return dp[ind][prev];
// 	}

// }

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> ele(n);
	vector<vector<int>> dp(n + 1, vector<int> (101, 0));
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    for(int i = n - 1; i >= 0; i--){
    	if(ele[i] == 0){
    		for(int j = 1; j <= m; j++){
    			if(i == n - 1){
    				dp[i][j] = 1;
    				continue;
    			}
    			if(j < m)
    				dp[i][j] = (dp[i][j] +  (dp[i + 1][j + 1])) % MOD;
    			if(j > 1){
    				dp[i][j] = (dp[i][j] +  dp[i + 1][j - 1]) % MOD;
    			}
    			dp[i][j] = (dp[i][j] + dp[i + 1][j]) % MOD;
    		}
    	}
    	else{
    		if(i == n - 1){
    			dp[i][ele[i]] = 1;
    			continue; 
    		}
    		if(ele[i] > 1)
    			dp[i][ele[i]] = (dp[i][ele[i]] + dp[i + 1][ele[i] - 1]) % MOD;
    		if(ele[i] < m){
    			dp[i][ele[i]] = (dp[i][ele[i]] + dp[i + 1][ele[i] + 1]) % MOD;
    		}
    		dp[i][ele[i]] = (dp[i][ele[i]] + dp[i + 1][ele[i]]) % MOD;
    	}
    }
    ll ans = 0;
    // for(int i = 0; i < n; i++){
    // 	for(int j = 0; j <= 100; j++){
    // 		cout << dp[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }
    for(int i = 1; i <= m; i++){
    	ans = (ans + dp[0][i]) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}