#include <bits/stdc++.h>

using namespace std;



void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    int x;
    cin >> x;
    a[x] = 1;
    int f = 0;
    for(int i = 1; i < n; i++){
    	int x;
    	cin >> x;
    	if(x < n && a[x + 1] == 1){
    		a[x] = 1;
    	} else if(x > 0 && a[x - 1] == 1){
    		a[x] = 1;
    	} else {
    		f = 1;
    	}
    }
    if(!f)
    	cout << "YES\n";
    else {
    	cout << "NO\n";
    }
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