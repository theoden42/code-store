

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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	a[i]--;
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
    	int x;
    	cin >> x;
    	adj[x].push_back(i);
    	adj[i].push_back(x);
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    int ans = 0;
    function<void(int,int)> dfs = [&](int source, int parent){
    	int zero = 0;
    	int one = 0;
    	for(auto x: adj[source]) if (x != parent){
    		// debug(source, x);
    		dfs(x, source);
    		zero += dp[x][0];
    		zero %= MOD;
    		one += dp[x][1];
    		one %= MOD;
    	}
    	for(auto x: adj[source]) if(x != parent){
    		ans += (dp[x][1] * (zero - dp[x][0] + MOD) % MOD) % MOD;
    		ans %= MOD;
    	}
    	int temp = 0;
    	for(auto x: adj[source]) if(x != parent){
    		if(a[source]){
    			temp += (dp[x][0] * (zero - dp[x][0] + MOD) % MOD) % MOD;
    			temp %= MOD;
    		} else {
    			temp += (dp[x][1] * (one - dp[x][1] + MOD) % MOD) % MOD;
    			temp %= MOD;
    		}
    	}

    	ans += (temp * modinverse(2)) % MOD;
    	ans %= MOD;

    	if(a[source]){
    		dp[source][1] = 1 + one + zero;
    		dp[source][1] %= MOD;
    		dp[source][0] = zero;
    		dp[source][0] %= MOD;
    	} else {
    		dp[source][0] = 1 + zero + one; 
    		dp[source][0] %= MOD;
    		dp[source][1] = one;
    		dp[source][1] %= MOD;
    	}
    };
    dfs(1, -1);
    ans += dp[1][0] + dp[1][1];

    ans %= MOD;
    ans -= n;
    ans += MOD;
    ans %= MOD;

    cout << ans << "\n";
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