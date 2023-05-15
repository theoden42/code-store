
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long


const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void query(int l, int r){
	cout << "? " << l <<  " " << r << endl;
	return;
}

void solve() {
	int n, t, k;
	cin >> n >> t;
	cin >> k;
	int l = 0;
	int r = n - 1;
	int index = -1;
	while(l <= r){
		int x;
		int mid = l + (r - l)/2;
		query(1, mid + 1);
		cin >> x;
		int val = mid + 1 - x;
		if(val == k){
			index = mid;
			r = mid - 1;
		}
		else if(val < k){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}
	}
	cout << "! " << index + 1 << endl;
}

int32_t main() {
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}