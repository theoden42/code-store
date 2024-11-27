

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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	sort(all(a));

	int s = accumulate(all(a), 0ll);

	vector<int> dp(s + 1), ndp(s + 1);
	dp[0] = 1;

	int ans = 0;

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= s; j++){	
			ndp[j] += dp[j];
			ndp[j] %= MOD;

			if(j - a[i] >= 0){
				ndp[j] += dp[j - a[i]];
				ndp[j] %= MOD;
			}
		}


		int j = 0;
		while(j <= s && (j + a[i] + 1) / 2 <= a[i]){
			int val = a[i];
			int num = dp[j];
			int add = (val * num);
			add %= MOD;
			ans += add;
			ans %= MOD;
			j += 1;
		}

		while(j <= s){
			int val = (j + a[i] + 1) / 2;
			int num = dp[j];
			int add = (val * num);
			add %= MOD;
			ans += add;
			ans %= MOD;
			j += 1;
		}

		dp.assign(all(ndp));
		ndp.assign(s + 1, 0ll);
	}

	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}