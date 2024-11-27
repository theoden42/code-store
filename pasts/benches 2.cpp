#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> ar(n);

	int max = 0;

	for(int i = 0; i<n; i++){
		cin >> ar[i];
		if(max < ar[i]){
			max = ar[i];
		}
	}
	int sum = 0;


	for(int i = 0; i<n; i++){
		sum += max - ar[i];
	}
	int minans = 0, maxans = 0;
	maxans = max + m;


	if(m <= sum){
		minans = max;
	}
	else{
		m = m - sum;
		minans = max + ceil((double)m/n);
	}
	cout << minans << " " << maxans << "\n";
}