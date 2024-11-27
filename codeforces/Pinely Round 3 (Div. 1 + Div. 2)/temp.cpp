#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int dfs(int i, int j, int sum, vector<int>& a, vector<vector<int>>& dp){
	if(dp[i][j] != -1)
		return dp[i][j];

	if(j - i <= 1)
		return 0;

	int mx = 0;
	if(a[i] + a[j] == sum){
		mx = max(mx, 1 + dfs(i + 1, j - 1, sum, a, dp));
	}
	if(a[i] + a[i + 1] == sum){
		mx = max(mx, 1 + dfs(i + 2, j, sum, a, dp));
	}
	if(a[j] + a[j - 1] == sum){
		mx = max(mx, 1 + dfs(i, j - 2, sum, a, dp));
	}

	return dp[i][j] = mx;
}


int solution(vector<int>& a){
	int n = a.size();
	vector<vector<int>> dp(n, vector<int>(n, -1));	
	int m1 = dfs(1, n - 2, a[0] + a[n - 1], a, dp);
	dp.assign(n, vector<int>(n, -1));
	int m2 = dfs(0, n - 3, a[n - 1] + a[n - 2], a, dp);
	dp.assign(n, vector<int>(n, -1));
	int m3 = dfs(2, n - 1, a[0] + a[1], a, dp);

	return max({1 + m1, 1 + m2, 1 + m3});
}

int main(){
	vector<int> nums = {4, 1, 4, 3, 3, 2, 5, 2};
	cout << solution(nums) << endl;
}