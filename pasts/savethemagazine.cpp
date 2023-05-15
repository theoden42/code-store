
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


int  maxsave(int n, vector<int>& ele, string& s, int flid, vector<vector<int>>& dp){

	if(dp[n][flid] != -1){
		return dp[n][flid];
	}

	if(n == 0){
		if(s[n] == '1'){
			dp[n][flid] = ele[0];
			return ele[0];
		}

		if(flid == 0){
			dp[n][flid] = 0;
			return 0;
		}
		else{
			dp[n][flid] = ele[n];
			return dp[n][flid];
		}
	}

	if(flid == 1){
		if(s[n] == '1'){
			dp[n][flid] = maxsave(n - 1, ele, s, 1, dp) + ele[n];
		}
		else{
			dp[n][flid] = maxsave(n - 1, ele, s, 0, dp) + ele[n];
		}
	}
	else{
		if(s[n] == '1'){
			dp[n][flid] = max(maxsave(n - 1, ele, s, 1, dp), maxsave(n - 1, ele, s, 0, dp) + ele[n]);
		}
		else{
			dp[n][flid] = maxsave(n - 1, ele, s, 0, dp);
		}
	} 
	return dp[n][flid];	
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    string s;
    cin >> s;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << maxsave(n - 1, ele, s, 0, dp) << "\n";

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