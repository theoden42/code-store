#include <bits/stdc++.h>
using namespace std;

void solve(){
	int hh = 0;
	int mm = 0;
	cin >> hh >> mm;
	int time = (24 - (hh + 1)) * 60 + (60 - mm);
	cout << time << endl;
}

int main(){
	int t = 1;
	cin >> t;
	while(t-- > 0){
		solve();
	}
}