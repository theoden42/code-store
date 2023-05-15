
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
		ll l, r;
		cin >> l >> r;
		ll a = (ll)sqrtl(l);
		ll b = (ll)sqrtl(r);
		debug(a, b);


		if(a == b){
			
			ll val = 0;
			for(int i = 0; i < 3; i++){
				ll x = a * a + i * a;
				if(x >= l && x <= r){
					val++;
				}
			}
			cout << val << "\n";
			return;
		}

		ll ans = 0;

		ans += (b - a - 1) * 3;	

		ll val = 0;
		for(int i = 0; i < 3; i++){
			ll x = (a * a + i * a);
			if(x >= l && x <= r){
				val++;
			}
		}

		for(int i = 0; i < 3; i++){
			ll x = (b * b + i * b);
			if(x >= l && x <= r){
				val++;
			}
		}
		ans += val;

		cout << ans << "\n";

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