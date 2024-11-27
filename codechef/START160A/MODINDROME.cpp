

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
const ll mod = 998244353;
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
    int n, m;
    cin >> n >> m;	
    int ans = 0;
    int pr = n / 2;
    int fix = (n + 1) / 2;
    for(int x = 1; x <= m; x++){
    	int cmp = m / x;
    	int mr = m % x;
    	int rem = (x - mr);
    	int t = cmp * (cmp + 1);
    	int sum = (t * mr);
    	t = cmp * (cmp - 1);
    	sum += (t * rem);
    	if(sum != m){
    		sum %= MOD;
    		int tsum = sum * binpow(m, fix - 1);
    		tsum %= MOD;
    		int r = sum * modinverse(m);
	   		r %= MOD;	
	    	int rn = binpow(r, pr);
	    	int div = (r - 1 + MOD) % MOD;
	    	tsum *= (rn - 1 + MOD) % MOD;
	    	tsum %= MOD;
	    	tsum *= modinverse(div);
	    	tsum %= MOD;
	    	ans += tsum;
    		ans %= MOD;
    	} else {
    		sum %= MOD;
    		int tsum = sum * binpow(m, fix - 1);	
    		tsum %= MOD;
    		ans += (tsum * pr) % MOD;
    		ans %= MOD;
    	}

    	debug(ans);
    }
    // suppose all are fixed
    ans -= binpow(m, fix);
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