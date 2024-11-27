#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, q;
	cin >> n >> q;
	vector<int> vr(n);
	for(int i = 0; i<n; i++){
		cin >> vr[i];
	}
	vector<int> sum(n, 0);
	sum[0] = vr[0];
	for(int i = 1; i<n; i++){
		sum[i] = vr[i] + sum[i-1];
	}
	for(int i = 0; i<q; i++){
		int a, b;
		cin >> a >> b;
		cout << (sum[b] - sum[a] + vr[a]) << "\n";
	}
}