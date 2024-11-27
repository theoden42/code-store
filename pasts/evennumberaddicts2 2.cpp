
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

int winner(int odd, int even, int move, vector<vector<vector<int>>>& dp){

	if(dp[odd][even][move] != -1)
		return dp[odd][even][move];

	if(odd == 0)
		return 0;
	if(even == 0){
		int val = (odd + 1) / 2;
		if(val & 1)return 1;
		else return 0;
	}
	dp[odd][even][move] |= winner(odd, even - 1, (move + 1) % 2, dp);
	dp[odd][even][move] |= 1 - winner(odd - 1, even, (move + 1) % 2, dp);

	return dp[odd][even][move];
}


void solve() {	
	int n;
	cin >> n;
	vector<int> ele(n, 0);
	int odd = 0, even = 0;
	for(int i = 0; i < n; i++){
		cin >> ele[i];
		if(ele[i] & 1)odd++;
		else even++;
	}

	vector<vector<vector<int>>>dp(101, vector<vector<int>>(101, vector<int>(2, -1)));

	if(winner(odd, even, 0, dp)){
		cout << "Bob" << "\n";
	}
	else{
		cout << "Alice" << "\n";
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