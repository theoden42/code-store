#include <bits/stdc++.h>
using namespace std;

int main(){

	long long int n, x;
	cin >> n >> x;
	int count = 0;
	for(int i = 1; i*i <= x ; i++){
		if(x % i == 0){
			if(i <= n && x/i <= n){
				if(i != x/i){
					count += 2;
				}
				else{
					count++;
				}
			}
		}
	}
	cout << count << '\n';
	return 0;
}