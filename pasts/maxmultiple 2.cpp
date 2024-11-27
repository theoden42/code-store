
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

int maxmul(int index, int d, int rem, int k, vector<int>& ele, vector<vector<vector<int>>>& dp){

	if(k == 0){
		if(rem == 0){
			return dp[index][rem][k] = 0;
		}
		else{
			return dp[index][rem][k] = -1;
		}
	}

	if(index == 0){
		if(rem == ele[index] % d && k == 1){
			return dp[index][rem][k] = ele[index];
		}
		else{
			return dp[index][rem][k] = -1;
		}
	}
	if(dp[index][rem][k] != -2)return dp[index][rem][k];

	dp[index][rem][k] = -1;

	int val1 = maxmul(index - 1, d, (rem - ele[index] % d + d) % d, k - 1, ele, dp);

	if(val1 != -1){
		dp[index][rem][k] = val1 + ele[index];
	}

	int val2 = maxmul(index - 1, d, rem, k, ele, dp);

	dp[index][rem][k] = max(dp[index][rem][k], val2);

	return dp[index][rem][k];

}

void solve() {

	int n, k, d;
	cin >> n >> k >> d;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
    sort(all(ele));

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(d, vector<int>(k + 1, -2)));

    debug(dp);

    cout << maxmul(n - 1, d, 0, k, ele, dp) << "\n";

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