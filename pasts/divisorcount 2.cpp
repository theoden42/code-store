#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	int count = 0;
	cin >> n;
	for(int i = 1; i<=n; i++){
		count += n/i; 
	}
	cout << count << '\n';

	return 0;
}