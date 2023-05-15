#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	int count = 0;
	while(n!=0){
		int val = n % 10;
		if(val == 4 || val == 7){
			count++;
		}
		n /= 10;
	}
	int flag = 0;
	if(count == 0){
		flag = 1;
	}
	while(count != 0){
		int val = count % 10;
		if(val != 4 && val != 7){
			flag = 1; 
			break;
		}
		count /= 10;
	}
	if(flag){
		cout << "NO" << '\n';
	}
	else{

		cout << "YES" << '\n';
	}
	return 0;

}