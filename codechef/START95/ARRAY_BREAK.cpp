

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    string s;
    cin >> s;

    int dp[k + 1][n + 1][n + 1];

    for(int i = 0; i <= k; i++){
    	for(int j = 0; j <= n; j++){
    		for(int k = 0; k <= n; k++){
    			dp[i][j][k] = 0;
    		}
    	}
    }

    for(int l = 1; l <= n; l++){
    	int sum = 0;
    	for(int r = l; r <= n; r++){
    		sum += a[r];
    		sum %= MOD;
    		dp[k][l][r] = sum;
    	}
    }

    for(int i = k - 1; i >= 0; i--){
    	for(int l = 1; l <= n; l++){
    		for(int r = l; r <= n; r++){

    			int len = r - l + 1;
    			if(len == 1){
    				dp[i][l][r] += a[l];
    				dp[i][l][r] %= MOD;
    				continue;
    			}

    			int prob = (1 * modinverse(len - 1)) % MOD;
    			for(int x = l; x <= r - 1; x++){
    				if(s[i] == 'L'){
    					dp[i][l][r] += (prob * dp[i + 1][l][x]) % MOD;
    					dp[i][l][r] %= MOD;
    				}
    				else{
    					dp[i][l][r] += (prob * dp[i + 1][x + 1][r]) % MOD;
    					dp[i][l][r] %= MOD;
    				}
    			}
    		}
    	}
    }

    // for(int i = 0; i <= k; i++){
    // 	for(int l = 0; l <= n; l++){
    // 		for(int r = l; r <= n; r++){
    // 			debug(i, l, r, dp[i][l][r]);
    // 		}
    // 	}
    // }

    cout << dp[0][1][n] << "\n";

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