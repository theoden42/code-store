#include <bits/stdc++.h>
using namespace std;

#define ll long long int 

int main(){
	ll n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i<n; i++){
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	ll sum1 = 0;
	ll sum2 = 0;
	ll ans = 0;
	for(int i = 0; i<n/2; i++){
		sum1 += v[i];
	}
	for(int i = n/2; i<n; i++){
		sum2 += v[i];
	}
	ans = sum1 * sum1 + sum2 * sum2;
	cout << ans << "\n";

}