#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];

	int sum = accumulate(v.begin(), v.end(), 0ll);	
	vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= sum; j++){
			dp[i + 1][j] += dp[i][j];
			if(j + v[i] <= sum){
				dp[i + 1][j + v[i]] += dp[i][j];
			} 
		}
	}
	int cnt = 0;
	for(int i = 0; i <= sum; i++){
		if(__builtin_popcount(i) == k){
			cnt += dp[n][i];
		}
	}
	cout << cnt << "\n";
}