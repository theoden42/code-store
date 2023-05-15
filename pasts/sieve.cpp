#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> prime(n+1);
	prime[0] = prime[1] = 1;

	for(int i = 2; i<= n; i++){
		if(prime[i] != 1){
			for(int j = 2; j*i <= n; j++){
				prime[j*i] = 1;
			}
		}
	}
	string s = "";
	int count = 0;
	for(int i = 0; i<=n; i++){
		if(prime[i] != 1){
			count ++;
			s+= to_string(i) + " ";
		}
	}
	cout << count << '\n' << s << '\n';
}