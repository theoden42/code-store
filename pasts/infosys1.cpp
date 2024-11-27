#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> freq(n);
	for(int i = 0; i < n; i++)
		cin >> freq[i];
	sort(freq.begin(), freq.end());
	int sum = accumulate(freq.begin(), freq.end(), 0ll);
	int ans = 0;
	for(int i = n - 1; i >= 0; i -= 2){
		ans += sum;
		for(int j = i; j >= 0 && j >= i - 1; j--){
			sum -= freq[j];
		}
	}
	assert(sum == 0);
	cout << ans << "\n";
	return 0;
}