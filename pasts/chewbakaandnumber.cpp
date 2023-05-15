
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {	
	ll x;
	cin >> x;
	ll t = x;
	int count = 0;
	while(t != 0){
		count++;
		t /= 10;
	}
	vector<int> ans(count, 0);
	int k = count - 1;
	while(x != 0 && k >= 0){
		int r = x % 10;
		if(r >= 5)
		r = 9 - r;
		if(k == 0 && r == 0){
			ans[k] = 9;
		}
		else{
			ans[k] = r;
 		}
 		k--;
 		x /= 10;
	}
	for(int i = 0; i < count; i++){
		cout << ans[i];
	}
	cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}