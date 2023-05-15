
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

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

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}


void solve() {
    int n;
    cin >> n;

    int a1 = n;
   	a1 = (a1 * (n + 1)) % MOD;
   	a1 = (a1 * (2 * n + 1)) % MOD;
   	a1 = (a1 * modinverse(6, MOD)) % MOD;

   	int a2 = n - 1;
   	a2 = (a2 * n) % MOD;
   	a2 = (a2 * (2 * n - 1)) % MOD;
   	a2 = (a2 * modinverse(6, MOD)) % MOD;

   	int a3 = n - 1;
   	a3 = (a3 * n) % MOD;
   	a3 = (a3 * modinverse(2, MOD)) % MOD;

   	int ans = (((a1 + a2) % MOD) + a3) % MOD;
   	ans = (ans * 2022ll) % MOD;
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