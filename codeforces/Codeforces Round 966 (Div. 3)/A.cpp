#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	if(s.size() < 3){
		cout << "NO\n";
		return;
	} 
	if(s[0] != '1' || s[1] != '0'){
		cout << "NO\n";
		return;
	}
	if(s[2] - '0' < 2 && s.size() <= 3){
		cout << "NO\n";
		return;
	} else if(s[2] - '0' == 0){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}