

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


vector<int> fac(2e5 + 1);
vector<int> inv(2e5 + 1);

void pre(){
	fac[0] = 1;
    inv[0] = 1;
	for(int i = 1; i < 2e5 + 1; i++){
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
		inv[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	if(r > n)
		return 0;
	int ans = fac[n];
	ans *= inv[r];
	ans %= MOD;
	ans *= inv[n - r];
	ans %= MOD;
	return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int c0 = 0, c1 = 0;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	if(x == 1){
    		c1 += 1;
    	} else {
    		c0 += 1;
    	}
    }

    int ans = 0;
    for(int i = (k / 2 + 1); i <= k; i++){
        int v1 = ncr(c1, i);
        v1 *= ncr(c0, k - i);
        v1 %= MOD;
        ans += v1;
        ans %= MOD;
    }

    cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    pre();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}