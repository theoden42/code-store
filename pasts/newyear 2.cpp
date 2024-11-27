#include <bits/stdc++.h>
using namespace std;

void solve(){
	vector<int> ar(3);
	cin >> ar[0] >> ar[1] >> ar[2];
	sort(ar.begin(), ar.end());
	if(ar[2] > ar[1] + ar[0] + 1){
		cout << "NO\n";
	}
	else{
		cout << "YES\n";
	}
}

int main(){
	int t = 1;
	cin >> t;
	while(t-- > 0){
		solve();
	}
}