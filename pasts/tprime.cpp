#include <bits/stdc++.h>
using namespace std;

bool isprime(int a){

	if(a == 1){
		return false;
	}
	else{
		for(int i = 2; i*i <= a; i++){
			if(a % i == 0){
				return false;
			}
		}
		return true;
	}
}

int main(){

	long long int n;
	cin >> n;
	vector<long long int> ar(n);
	for(int i = 0; i<n; i++){
		cin >> ar[i];
	}

	for(int i = 0; i<n; i++){
		long long int st = sqrt(ar[i]);
		
		if(ar[i] % st == 0 && st * st == ar[i]){
			if(isprime(st)){
				cout<< "YES" <<'\n';
			}
			else{
				cout << "NO" << '\n';
			}
		}
		else{
			cout << "NO" << '\n';
		}
	}

	return 0;
}