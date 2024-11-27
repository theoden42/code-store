

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

#define int long long

const int MAX_N = 1e6 + 5;
const ll mod = 998244353;
const ll INF = 1e9;

void solve() {
	int n, m;
	cin >> n >> m;
	if(n > m){
		int x = n / 2;
		int lb = max(1ll, m - x);
		int ub = min(m, 1 + x);
		int su = (ub * (ub + 1)) / 2;
		su %= mod;
		su -= (lb * (lb - 1)) / 2;
		su %= mod;
		su += mod;
		su %= mod;

		int sum = ((n % 2 == 0) ? (n / 2 + n / 2 + 1) : n / 2 + 1);
		sum %= mod;
		su *= sum;
		su %= mod;
		cout << su << "\n";

	} else {
		int x = m / 2;
		int lb = max(1ll, n - x);
		int ub = min(n, 1 + x);
		int su = (ub * (ub + 1)) / 2;
		su %= mod;
		su -= (lb * (lb - 1)) / 2;
		su %= mod;
		su += mod;
		su %= mod;

		int sum = ((m % 2 == 0) ? (m / 2 + m / 2 + 1) : m / 2 + 1);
		sum %= mod;
		su *= sum;
		su %= mod;
		cout << su << "\n";
	}
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