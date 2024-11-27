#include <bits/stdc++.h>
using namespace std;

bool check(int n){
	while(n != 0){
		int digit = n % 10;
		if(digit != 4 && digit != 7){
			return false;
		}
		n /= 10;
	}
	return true;
}

int main(){
	int n;
	cin >> n;
	int flag = 0;
	for(int i = 1; i<=n; i++){
		if(n % i == 0){
			if(check(i)){
				flag = 1;
				break;
			}
		}
	}
	if(flag){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}