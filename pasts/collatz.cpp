#include <bits/stdc++.h>
using namespace std;

void collatz(long long n){
	if(n == 1){
		cout << '1' << "\n";
	}
	else if(n % 2 == 0){
		cout << (n) << "\n";
		collatz(n/2);
	}	
	else{
		cout << n << '\n';
		collatz(3 * n + 1);
	}
}

int main(){
	long long n; 
	cin >> n;
	collatz(n);
}