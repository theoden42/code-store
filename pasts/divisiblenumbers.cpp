
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


ll gcd (ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    ll a, b, c, d;

    cin >> a >> b >> c >> d;
    ll ab = a * b;


    for(ll x = a + 1; x <= c; x++){

    	ll lcm = (x * ab) / gcd(x, ab);

    	ll de = (x * b) / lcm;
		ll val = (de + 1) * lcm;
		ll y = val / x;

		debug(x, y);
		if(y > b && y <= d){
			cout << x << " " << y << "\n";
			return;
		}
    }
    cout << "-1 -1\n";
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