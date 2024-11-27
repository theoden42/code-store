

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
    	p[i] += p[i - 1];
    	p[i] += a[i - 1];
    }

    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--; r--;
    	int lcycle = l / n;
    	int rcycle = r / n;

    	int complete = rcycle - lcycle - 1;
    	int ans = p[n] * complete;
    	int lind = l % n;
    	int rind = r % n;
		int l_left = (lind + lcycle) % n;
		int r_left = (n - 1 + lcycle) % n;

		int sum = 0;
		if(r_left < l_left){
			sum += p[r_left + 1] + p[n] - p[l_left];
		} else {
			sum += p[r_left + 1] - p[l_left];
		}
		ans += sum;

		sum = 0;
		l_left = (0 + rcycle) % n;
		r_left = (rind + rcycle) % n;
		if(r_left < l_left){
			sum += p[r_left + 1] + p[n] - p[l_left];
		} else {
			sum += p[r_left + 1] - p[l_left];
		}
		ans += sum;

		cout << ans << "\n";
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