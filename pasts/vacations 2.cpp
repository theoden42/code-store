
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

void solve() {
    int n;
    cin >> n;
    vector<int> stat(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> stat[i];
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    dp[0][0] = 1;
    if(stat[0] == 1 || stat[0] == 3){
    	dp[0][2] = 0;
    }
    else{
    	dp[0][2] = 1;
    }
    if(stat[0] == 2 || stat[0] == 3){
    	dp[0][1] = 0;
    }
    else{
    	dp[0][1] = 1;
    }
    for(int i = 1; i < n; i++){
    	dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
    	if(stat[i] == 0){
    		dp[i][1] = dp[i][0];
    		dp[i][2] = dp[i][0];
    	}
    	else if(stat[i] == 1){
    		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    		dp[i][1] = dp[i][0];
    	}
    	else if(stat[i] == 2){
    		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    		dp[i][2] = dp[i][0];
    	}
    	else{
    		 dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    		 dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    	}
    }
    cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << "\n";
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