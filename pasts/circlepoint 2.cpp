#include <bits/stdc++.h>

using namespace std;


int main(){
	 long long n, p, ans;
	p = 1;
	ans = 0;
	cin >> n;
	for(int i = 1; i<=n; i++){
		p *= i;
	}
	for(int i = 1; i<n; i++){
		ans += p/(i * ( i + 1));
	}
	ans += p/n;
	cout << ans << "\n";
}