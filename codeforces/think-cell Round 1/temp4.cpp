#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int maximizeRatings(vector<int> ratings){

	int n = ratings.size();
	vector<int> dp(n + 1, -1e9);
	dp[n] = 0;

	for(int i = n - 1; i >= 0; i--){
		int v = ratings[i] + dp[i + 1];
		int v2 = 0;
		if(i == n - 1)
			v2 = 0;
		else 
			v2 = ratings[i + 1] + dp[i + 2];

		dp[i] = max({v, v2});
	}

	debug(dp);

	return dp[0];
}

int main(){
	int ans = maximizeRatings({9, -1, -3, 4, 5});
	cout << ans << "\n";
}