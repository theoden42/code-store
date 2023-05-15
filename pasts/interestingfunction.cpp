
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
	ll l, r;
	cin >> l >> r;
	ll count = 0;
	count += r - l;
	ll i = 10;
	while(i <= 1e9 && i <= r){
		ll temp = (i - l % i <= r - l) ? 1: 0;
		temp += max(0ll, (r - (l + i - l % i)) / i);
		count += temp;
		// cout << temp << " " << i << "\n";
		i = i * 10;
	}
	cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}