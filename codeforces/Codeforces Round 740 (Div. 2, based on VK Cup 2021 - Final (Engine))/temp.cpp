#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> price(n);
	map<int,int> mp;
	for(int i = 0; i < n; i++){
		cin >> price[i];
		mp[price[i]] += 1;
	}
	int k;
	cin >> k;
	long long count = 0;
	for(int i = 0; i < n; i++){
		int temp = mp[price[i] - k];
		if(k == 0){
			temp -= 1;
		}
		count += temp;	
	}

	if(k == 0){
		count /= 2;
	}
	cout << count << "\n";

}