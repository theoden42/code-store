

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
const ll mod = 1e9 + 7;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long

vector<int> fac(MAX_N);
vector<int> invfac(MAX_N);

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


void pre(){
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fac[i] = (fac[i - 1] * i) % mod;
		invfac[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	if(r > n)
		return 0;
	int ans = fac[n];
	ans *= invfac[n - r];
	ans %= mod;
	ans *= invfac[r];
	ans %= mod;
	return ans;
}

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        for(int val = 2 * i + 1; val >= i + 1; val -= 1){
            // i values shoudl be missing from left of val 
            int leftchoice = ncr(min(val - 1, n), i);
            int rightchoice = ncr(max(0ll, n - val), 2 * i - val + 1);
            int total = (leftchoice * rightchoice) % mod;
            total *= val;
            ans += total;
            ans %= mod;
        }
    }

    cout << ans << '\n';
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    pre();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}