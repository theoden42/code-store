
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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


int findvalue(int n, int pos, vector<int>& ele, vector<vector<int>>& dp){
	if(dp[n][pos] != -1e16){
		return dp[n][pos];
	}
	if(n == 0){
		if(pos == 0){
			dp[n][pos] = ele[n];
		}
		else if(pos == 1){
			dp[n][pos] = 0;
		}
		else{
			dp[n][pos] = 0;
		}
		return dp[n][pos];
	}

	if(pos == 0){
		dp[n][pos] = max(findvalue(n - 1, pos, ele, dp), findvalue(n - 1, 1, ele, dp) + ele[n]);

	}
	else {
		dp[n][pos] = max(findvalue(n - 1, pos, ele, dp), findvalue(n - 1, 0, ele, dp) - ele[n]);
	}
	return dp[n][pos];
}

void solve() {
   int n, q;
   cin >> n >> q;
   vector<int> ele(n, 0);
   for(int i = 0; i < n; i++){
   	cin >> ele[i];
   }
   	vector<vector<int>> dp(n, vector<int> (2, -1e16));
	debug(dp);
	cout << max(findvalue(n - 1, 1, ele, dp), findvalue(n - 1, 0, ele, dp)) << "\n";
	debug(dp);
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