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
ll mod = 1e9 + 7;
const ll INF = 1e9;

#define int long long

void solve() {
	int n, m;
	cin >> n >> m;
	mod = m;
	vector<int> diff(n + 2);
	vector<int> dp(n + 1);
	diff[1] = 1;
	diff[2] = mod - 1;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		if(i > 1){
			diff[i] += sum;
			diff[i] %= mod;
			diff[i + 1] -= sum;
			diff[i + 1] += mod;
			diff[i + 1] %= mod;
		}
		dp[i] = (dp[i - 1] + diff[i]) % mod;
		int curr = dp[i];
		for(int j = 2; j * i <= n; j++){
			int left = j * i;
			int right = min(n, j * (i + 1) - 1);
			diff[left] += curr;
			diff[left] %= mod;
			diff[right + 1] -= curr;
			diff[right + 1] += mod;
			diff[right + 1] %= mod;
		}
		sum += dp[i];
		sum %= mod;
	}
	cout << dp[n] << "\n";
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