#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> perm(n, 0);
	for(int i = 0; i<n; i++){
		cin >> perm[i];
	}
	int max = perm[0];
	int count  = 1;
	int flag = 1;
	for(int i = 1; i < n; i++){
		if(perm[i] > max && i >= max ){
			max = perm[i];
			count ++;
		}
		else if(perm[i] > max){
			max = perm[i];
		}

	}
	cout << count << "\n";
}

int main(){
	int t = 1;
	cin >> t;
	while(t-- > 0){
		solve();
	}
}