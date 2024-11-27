#include <bits/stdc++.h>
using namespace std;


void solve(){
	long long int n, x, y;
	cin >> n >> x >> y;
	long long int ar[n];
	long long int sum = 0;
	for(long long int i = 0; i<n; i++){
		cin >> ar[i];
		sum += ar[i];
	}
	if((sum % 2) == 0){
		if((x % 2) == (y %2)){
			cout <<"Alice" << '\n';
		}
		else{
			cout <<"Bob" << '\n';
		}
	}
	else{
		if((x % 2) == (y %2)){
			cout <<"Bob" << '\n';
		}
		else{
			cout <<"Alice" << '\n';
		}
	}
}

int main(){

	int t = 1;
	cin >> t;

	while(t-- > 0){
		solve();
	}

	return 0;
}