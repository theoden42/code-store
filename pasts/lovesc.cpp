#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n;
	cin >> n;
	if(n % 3 == 0){
		cout << 1 << " " << 1 << " " << n - 2 << "\n";
	}
	else{
		cout << 1 << " " << 2 << " " << n - 3 << "\n";
	}
	
	}