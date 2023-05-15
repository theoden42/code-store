
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
    vector<double> prob(n + 1, 0);
    for(int i = 1; i <= n; i++){
    	cin >> prob[i];
    }
    vector<vector<double>> dp(n + 1, vector<double>(n + 1, 0.0));
    dp[0][0] = 1;
    dp[1][0] = (1 - prob[1]);
    dp[1][1] = prob[1];
  	for(int i = 2; i <= n; i++){
  		for(int j = 0; j <= i; j++){
  			if(j > 0)
  				dp[i][j] = dp[i - 1][j] * (1 - prob[i]) + dp[i - 1][j - 1] * prob[i];
  			else
  				dp[i][j] = dp[i - 1][j] * (1 - prob[i]);
  		}
  	}
  	double sum = 0;
  	for(int i = n / 2 + 1; i <= n; i++){
  		sum += dp[n][i];
  	}
  	cout << setprecision(10) << sum << "\n";
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