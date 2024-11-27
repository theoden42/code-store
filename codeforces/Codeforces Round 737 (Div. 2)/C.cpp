

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
const ll mod = 1e9 + 7;
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

void solve() {
    int n, k;
    cin >> n >> k;
    int total = binpow(2, k);
    total = binpow(total, n);
    int sum = 0;
    int curr = 1;

    for(int i = k - 1; i >= 0; i--){
    	int setbit = binpow(2, n - 1);
    	if(n & 1){
    		setbit -= 1;
    		setbit += mod;
    		setbit %= mod;
    	}
		int total = (curr * setbit);
		total %= mod;
    	int temp = binpow(2, n);
    	temp = binpow(temp, i);
    	sum += (total * temp) % mod;
    	sum %= mod;

    	int ncurr = (binpow(2, n) - setbit + mod) % mod;
    	if(!(n & 1)){
    		ncurr -= 1;
    		ncurr += mod;
    		ncurr %= mod;
    	}

    	ncurr *= curr;
    	ncurr %= mod;
    	curr = ncurr;
    }

    int ans = (total - sum + mod) % mod;
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