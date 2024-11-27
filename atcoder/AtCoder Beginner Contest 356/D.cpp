

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

int gc(ll n, int k){
    long long res = (n >> (k + 1ll)) << k;
 
    if ((n >> k) & 1ll)
        res += n & ((1ll << k) - 1);

    return res % MOD;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    for(int k = 0; k < 64; k++){
    	if(m >> k & 1ll){
    		ans += gc(n + 1, k);
    		ans %= MOD;
    	}
    }

    cout << ans << '\n';
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