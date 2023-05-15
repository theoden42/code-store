
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



ll recur(int ind, vector<ll>& ele, vector<vector<ll>>& dp, int sign){
	if(ind == ele.size()){
		return 0;
	}

	if(dp[ind][sign] != -1) return dp[ind][sign];


	if(sign == 0){
		dp[ind][sign] = max(recur(ind + 1, ele, dp, 1) + ele[ind], recur(ind + 1, ele, dp, 0));
	}
	else{
		dp[ind][sign] = max(recur(ind + 1, ele, dp, 0) - ele[ind], recur(ind + 1, ele, dp, 1));
	}
	return dp[ind][sign];
}


void solve() {
    int n;
    cin >> n;
    vector<ll> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    debug(ele);
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    ll ans = recur(0, ele, dp, 0);
    cout << ans << "\n";	
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