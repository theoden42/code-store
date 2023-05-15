#include <bits/stdc++.h>
#define mod 1000000007ll
using namespace std;

int main(){

	long long x, y, n;
	cin >> x >> y >> n;

	if(x == 0 && y == 0){
		cout << 0 << "\n";
		return 0;
	}
	vector<long long> vn(7, 0);
	vn[0] = 0;
	vn[1] = x;
	vn[2] = y;
	for(long long i = 3; i <= 6; i++){
		vn[i] = (vn[i-1] % mod - vn[i-2] % mod + mod) % mod;
	}
	cout << (vn[(n - 1) % 6 + 1]  + mod) % mod << "\n";
}