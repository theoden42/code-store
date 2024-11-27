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

int ispossible(int ind, int sz, vector<int>& b, vector<int>& dp){
	debug(ind, sz);

	if(ind == (int)b.size()){
		return 1;
	}
	if(ind == (int)b.size() - 1){
		if(sz == b[ind]){
			dp[ind] = 1;
			return 1;
		}
		else{
			dp[ind] = 0;
			return 0;
		}
	}
	if(dp[ind] != 0){
		return dp[ind];
	}

	if(sz == b[ind]){
	 	dp[ind] = (ispossible(ind + 1, sz + 1, b, dp) || ispossible(ind + 1, 0, b, dp));
	}
	else if(sz == 0 && b[ind] + ind + 1 <= (int)b.size()){
		dp[ind] = ispossible(ind + 1, sz + 1, b, dp) || ispossible(ind + b[ind] + 1, 0, b, dp);
	}
	else{
		dp[ind] = ispossible(ind + 1, sz + 1, b, dp);
	}

	return dp[ind];
}


void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> dp(n + 1, 0);

    dp[n] = 1;

   	for(int i = n - 1; i >= 0; i--){
   		if(i + ele[i] + 1 <= n){
   			dp[i] = (dp[i] | dp[i + ele[i] + 1]);
   		}
   		if(dp[i + 1] == 1){
   			if(i - ele[i] >= 0){
   				dp[i - ele[i]] |= 1;
   			}
   		}
   	}
   	if(dp[0]){
   		cout << "YES" << "\n";
   	}
   	else{
   		cout << "NO" << "\n";	
   	}
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