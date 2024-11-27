

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
	int w, f;
	cin >> w >> f;
	int n;
	cin >> n;
	vector<int> s(n + 1);
	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}

	vector<int> dp(1e6 + 1), ndp(1e6 + 1);
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= 1e6; j++){
			ndp[j] = dp[j];
			if(j - s[i] >= 0){
				ndp[j] |= dp[j - s[i]];
			}
		}
		dp = ndp;
		for(int j = 0; j <= 1e6; j++){
			ndp[j] = 0;
		}
	}

	int sum = accumulate(all(s), 0ll);
	int mn = sum;
	for(int j = 0; j <= 1e6; j++){
		if(j > sum)
			break;
		if(dp[j] == 0)
			continue;

		int left = sum - j;
		int moves = max((j + w - 1) / w, (left + f - 1) / f);
		mn = min(mn, moves);
	}

	cout << mn << "\n";
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