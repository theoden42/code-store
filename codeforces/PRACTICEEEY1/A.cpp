

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

long double calc(int move, long double value, long double c, long double m, long double p, long double v){
	// debug(move, value, c, m);
	if((c < 1e-7 && m < 1e-7) || move > 20){
		return p * move * value;
	}
	long double ans = p * value * move;

	if(c > 0){
		long double newvalue = value * c;
		long double nm = 0;
		if(c > v){
			if(m > 1e-8){
				 nm = v / 2;
			}
			ans += calc(move + 1, newvalue, c - v, m + nm, p + v - nm, v);
		} else {
			if(m > 1e-8){
				nm = c / 2;
			}
			ans += calc(move + 1, newvalue, 0, m + nm, p + c - nm, v);
		}
	}
	if(m > 0){
		long double newvalue = value * m;
		long double nc = 0;
		if(m > v){
			if(c > 1e-8){
				nc = v / 2;
			}
			ans += calc(move + 1, newvalue, c + nc, m - v, p + v - nc, v);
		} else {
			if(c > 1e-8){
				nc = m / 2;
			}
			ans += calc(move + 1, newvalue, c + nc, 0, p + m - nc, v);
		}
	}
	return ans;
}

void solve() {
	long double c, m, p, v;
	cin >> c >> m >> p >> v;
	long double ans = calc(1, 1.0, c, m, p, v);
	cout << fixed <<  setprecision(20) << ans << "\n";
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