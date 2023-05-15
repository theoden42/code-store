#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; 
	int sum = 0; 
	int max = 0;
	cin >> n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++){
		int x;
		cin >> x;
		ar[i] = x;
	}
	vector<long long int> pre(n);
	pre[0] = ar[0];
	sum += ar[0];
	for(int i = 1; i<n; i++){
		pre[i] = ar[i] + pre[i-1];
		sum += ar[i];
		if(ar[i] > max){
			max = ar[i];
		}
	}
///
	for(int i = n; i>=1; i--){
		if(sum % i == 0){
			if(sum/i < max)
				continue;
			else{
				int count = 0;
				for(int j = 0; j<n; j++){
					if(pre[j] % (sum/i) == 0){
						count++;
					}
				}
				if(count == i){
					cout << (n - i) <<"\n";
					break;
				}
			}
		}
	}

}

int main(){

	int t;
	cin >> t;
	while(t--> 0){
		solve();
	}
	return 0;
}