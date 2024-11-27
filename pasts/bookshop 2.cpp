#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, x;
	cin >> n >> x;
	vector<int> price(n);
	vector<int> pages(n);
	for(int i = 0; i < n; i++){
		cin >> price[i];
	}
	for(int i = 0; i < n; i++){
		cin >> pages[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			dp[i][j] = dp[i - 1][j];
			int left = j - price[i - 1];
			if(left >= 0){
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);	
			}
		}
			
	}
	// ll m = 0;
	// for(int i = 0; i <= x; i++){
	// 	for(int j = 0; j <= n; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }

	cout << dp[n][x] << "\n";
}