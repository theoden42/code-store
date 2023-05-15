
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
    int n, l;
    cin >> n >> l;
    vector<ll> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    sort(ele.begin(), ele.end());
   	ll m = 0;
   	ll x = 0;
   	for(int i = 0; i < n - 1; i++){
  		m = max(m, ele[i + 1] - ele[i]);
   	}
   	ld ans = max((double)max(ele[0], l - ele[n - 1]), m / 2.0);
   	cout << setprecision(10) << ans  << "\n";
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