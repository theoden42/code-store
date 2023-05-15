#include <bits/stdc++.h>
using namespace std;

int main(){
	int n ;
	cin >> n;
	int count = 0;
	if(n % 2 == 0){
		count = n/2;
		cout << count << '\n';
		for(int i = 0; i<count; i++){
			cout << "2" << " ";
		}
		cout << '\n';
	}
	else{
		count = (n-3)/2;
		cout << count + 1 << '\n';
		for(int i = 0; i<count; i++){
			cout << "2" << " ";
		}
		cout << "3" << '\n';
	}
	return 0;
}