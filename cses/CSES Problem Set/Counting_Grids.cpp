

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

    int sum = 0;
    int sum2 = 0;
    if(n & 1){
		int v = (n - 1) / 2;
		sum = (v * (v + 1));
        sum2 += 2 * sum;
        sum += 1;
        sum2 += 1;
    } else {
    	int term = n / 2;
    	int v = (n - 1) / 2;
    	sum += term;
    	sum += (v * (v + 1));
        sum2 += (2 * sum);
    }

    int sum3 = n * n;
    int ans = 0;

    ans += binpow(2, sum3);
    ans %= MOD;
    ans += binpow(2, sum);
    ans %= MOD;
    ans += binpow(2, sum2);
    ans %= MOD;
    ans += binpow(2, sum);
    ans %= MOD;

    ans *= modinverse(4);
    ans %= MOD;

    cout << ans << "\n";
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