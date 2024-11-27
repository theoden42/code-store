

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

#define int long long

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> b(n);
	for(int i = 0; i < n - 1; i++){
		cin >> b[i];
	}
	int curr = 0;
	int days = 0;
	int mx = 1e9 + 5;
	for(int i = 0; i < n; i++){
		// curr + d * a[i] >= c
		int mday = (c - curr + a[i] - 1) / a[i];
		mday = max(0ll, mday); 
		mx = min(mx, mday + days);

		int upday = (b[i] - curr + a[i] - 1) / a[i];
		upday = max(0ll, upday);
		days += 1 + upday;
		curr = curr + a[i] * upday - b[i];
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