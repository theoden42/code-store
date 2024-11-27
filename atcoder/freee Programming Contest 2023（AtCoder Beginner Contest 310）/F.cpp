

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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(11, 0));

	dp[0][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp[i][j] = (dp[i - 1][j] * a[i - 1]) % MOD;
		}
		for(int k = 1; k <= a[i - 1] && k <= 10; k++){
			for(int j = 0; j <= 10; j++){
				if(j + k <= 10){
					dp[i][j + k] += dp[i - 1][j];
					dp[i][j + k] %= MOD;
				}
			} 
		}
	}

	debug(dp);

	int total = 1;
	for(int i = 0; i < n; i++){
		total *= a[i];
		total %= MOD;
	}

	int ways = (dp[n][10] * modinverse(total)) % MOD;
	cout << ways << "\n";
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