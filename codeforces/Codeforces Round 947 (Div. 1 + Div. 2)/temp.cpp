#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int t;
	cin >> t;
	vector<int> dp(t + 1, 1e9);
	dp[0] = 0;
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < n; j++){
			if(i - a[j] >= 0){
				dp[i] = min(dp[i], dp[i - a[j]] + 1);
			}
		}
	}
	if(dp[t] == 1e9)
		cout << "-1\n";
	else 
		cout << dp[t] << "\n";
}