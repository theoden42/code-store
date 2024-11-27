

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

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<long double>> dp(n + 1, vector<long double>(6 * n + 1));
	dp[0][0] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 6 * n; j++){
			for(int k = j + 1; k <= j + 6 && k <= 6 * n; k++){
				dp[i + 1][k] += dp[i][j] / 6;
				debug(dp[n][4]);	
			}
		}
	}



	debug(dp);

	for(int j = 1; j <= 6 * n; j++){
		dp[n][j] += dp[n][j - 1];
	}


	long double ans = dp[n][b] - dp[n][a - 1];
	cout << fixed << setprecision(6) <<  ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}