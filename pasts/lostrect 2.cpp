#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a = 0;
	cin >> a;
	long long max = 1e12;
	for(long long i = 1; i <= sqrt(a); i++){
		if(a % i == 0){
			long long peri = 2 * (i + a/i);
			if(max > peri){
				max = peri;
			}
		}
	}
	cout << max << '\n';

}