

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}

vector<int> fac(MAX_N + 1, 1);
vector<int> invfac(MAX_N + 1, 1);

void pre(){
	for(int i = 1; i <= MAX_N; i++){
		fac[i] = (i * fac[i - 1]) % MOD;
		invfac[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	int x = fac[n];
	x *= invfac[n - r];
	x %= MOD;
	x *= invfac[r];
	x %= MOD;
	return x;
}

void solve() {
	int n, k;
	cin >> n >> k;
	int count = binpow(2, n - 1);
	int ans = binpow(count, k);
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