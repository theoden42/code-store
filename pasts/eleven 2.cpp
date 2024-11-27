#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a = 1; 
	int b = 1;
	vector<int> fib(1001, 0);
	fib[1] = 1;
	fib[2] = 1;
	a = 1; b = 1;
	while(b <= 1000){
		fib[b] = 1;
		int temp = b;
		b = a + b;
		a = temp;
	}
	string s = "";
	for(int i = 1; i<=n; i++){
		if(fib[i] == 1){
			s += 'O';
		}
		else{
			s += 'o';
		}
	}
	cout << s << "\n";
}