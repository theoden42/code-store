#include <bits/stdc++.h>
using namespace std;

long long getThreeNonOverlappingIntervals(vector<int> starting, vector<int> ending){
	int n = starting.size();
	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		vp[i] = {starting[i], ending[i]};
	}

	sort(vp.begin(), vp.end());
	vector<long long> dp(n + 1);

	for(int i = 0; i < n; i++){
		int r = vp[i].second;
		int lb = i;
		int ub = n - 1;
		int ans = n;
		while(lb <= ub){
			int mid = (lb + ub) / 2;
			if(vp[mid].first > r){
				ans = mid;
				ub = mid - 1;
			} else { 
				lb = mid + 1;
			}
		}
		dp[i] =	n - ans;
	}

	for(int i = n - 2; i >= 0; i--){
		dp[i] += dp[i + 1];
	}
	int sum = 0;
	for(int i = 0; i < n; i++){
		int r = vp[i].second;
		int lb = i;
		int ub = n - 1;
		int ans = n;
		while(lb <= ub){
			int mid = (lb + ub) / 2;
			if(vp[mid].first > r){
				ans = mid;
				ub = mid - 1;
			} else {
				lb = mid + 1;
			}
		}
		sum += dp[ans];
	}
	return sum;
}

int main(){
	int ans = getThreeNonOverlappingIntervals({1, 2, 3, 4}, {1, 2, 3, 4});
	cout << ans << "\n";
}