

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}

int sum(int l, int r){
    l %= MOD;
    r %= MOD;
    int x = r * (r + 1);
    x %= MOD; 
    int y = l * (l - 1);
    y %= MOD;

    x -= y;
    x += MOD;
    x %= MOD;

    x *= modinverse(2);
    x %= MOD;

    return x;       
}


void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int lst = 0;
    for(int i = 1; i * i <= n; i++){
        int x = i * (n / i);
        x %= MOD;
        ans += x;
        ans %= MOD;
        lst = n / i;
    }
    for(int i = 1; i < lst; i++){
        int lb = n / (i + 1);
        int ub = n / i;
        int s = sum(lb + 1, ub);

        s *= i; 
        s %= MOD;
        ans += s;
        ans %= MOD;
    }

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