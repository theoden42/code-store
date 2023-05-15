#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;


ll comb(ll n, ll k, vector<ll> fac){
	ll ans = 1;
	int flag = 1;
	if(n - k >= n/2){
		k = n - k;
	}
	int i = 0;
	for(i = k + 1; i <= n; i++){
		ans *= i;
		if(ans % fac[n - k] == 0 && flag == 1){
			ans /= fac[n - k];
			flag = 0;
		}
	}
	return ans;
}

int main(){
	ll n; 
	ll sum  = 0;
	cin >> n;
	vector<ll> fac(21, 0);
	fac[0] = 1;
	fac[1] = 1;

	for(int i = 1; i<=20; i++){
		fac[i] = i * fac[i-1];

	}

	int k;

	if(n % 2 == 0){
		k = 0;
	}
	else{
		k = 1;
	}

	for(int i = k; i <= n; i += 2){
		sum += comb((n + i)/2, i , fac);
	}

	cout << sum << "\n";
}