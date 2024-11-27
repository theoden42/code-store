

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
    int m, n;
    cin >> m >> n;
    vector<int> s(m + 1), l(m + 1);
    for(int i = 1; i <= m; i++)
    	cin >> s[i];
    for(int i = 1; i <= m; i++)
    	cin >> l[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][1] = 1;

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		for(int k = 1; k <= m; k++){
    			int val = dp[i - 1][k];
    			int temp = s[k] * l[j];
    			temp %= MOD;
    			temp += (s[j] * l[k]) % MOD;
    			temp %= MOD;
                temp += (s[j] * s[k]) % MOD;
                temp %= MOD;
    			dp[i][j] += (temp * dp[i - 1][k]) % MOD;
                dp[i][j] %= MOD;
    		}
    	}
    }

    int finans = 0;
    for(int i = 1; i <= m; i++){
    	finans += dp[n][i];
    	finans %= MOD;
    }

    cout << finans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}