#include <bits/stdc++.h>
#include <debug.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> ranges;
	for(int i = 1; i <= n; i++){
		vector<int> v;
		for(int j = 1; j <= m; j++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		ranges.push_back({v[0], v.back()});
	}

	sort(ranges.begin(), ranges.end());
	vector<vector<int>> ans;
	for(int i = 0; i < ranges.size(); i++){
		if(i != 0 && ranges[i][0] < ans.back()[1]){
			ans.back()[1] = max(ans.back()[1], ranges[i][1]);
		} else {
			ans.push_back(ranges[i]);
		}
		debug(ans);
	}
	cout << ans.size() << "\n";
}