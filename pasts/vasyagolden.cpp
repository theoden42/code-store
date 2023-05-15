#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<int> vr(n, 0);
	vector<int> factors;
	vr[0] = s[0] - '0';
	for(int i = 1; i<n; i++){
		vr[i] = vr[i - 1] + s[i] - '0';
	}
	int sum = vr[n-1];
	if(sum == 0){
		cout << "YES" << "\n";
		return 0;
	}
	else if(sum == 1){
		cout << "NO" << "\n";
		return 0;
	}
	for(int i = 1; i * i <= sum; i++){
		if(sum % i == 0){
			factors.push_back(i);
			if(sum/i != i && sum/i != sum){
				factors.push_back(sum/i);
			}
		}
	}
	for(auto f: factors){
		int k = 1;
		for(int i = 0; i<n; i++){
			if(vr[i]  == f * k){
				k++;
			}
		}
		if(k - 1 == sum/f ){
			cout << "YES" << "\n";
			return 0;
		}
	}
	cout << "NO" << "\n";
	return 0;
}