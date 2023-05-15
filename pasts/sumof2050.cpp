
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
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    ll n;
    cin >> n;
    if(n % 2050 != 0){
    	cout << "-1" << "\n";
    }
    else{
    	ll x = n / 2050;
		ll y = x;
		ll count = x % 10;
		ll k = 1e18;
		while(k != 1){
			count += y / k;
			y = y % k;
			k = k / 10;
		}
		cout << count << "\n";
	}
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