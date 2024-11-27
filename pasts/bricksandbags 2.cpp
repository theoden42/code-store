
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int n;
	cin >> n;
	vector<int> ele(n);
	for(int i = 0; i < n; ++i){
		cin >> ele[i];
	}

	ll mx = 0;
	sort(all(ele));



	mx += (ele[n - 1] - ele[0]);
	mx += (ele[n - 1] - ele[n - 2]);


	for(int i = n - 1; i >= 2; i--){
		ll val = ele[i] - ele[0];
		val += ele[i] - ele[i - 1];
		mx = max(mx, val);
	}

	for(int i = 0; i < n - 2; i++){
		ll val = ele[n - 1] - ele[i];
		val += (ele[i + 1] - ele[i]);
		mx = max(mx, val);
	}

	cout << mx << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}