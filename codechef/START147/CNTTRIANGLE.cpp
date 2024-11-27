

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

vector<int> fac(MAX_N), inv(MAX_N);

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
	inv[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fac[i] = fac[i - 1] * i;
		fac[i] %= MOD;
		inv[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	if(r > n)
		return 0;
	int ans = fac[n];
	ans *= inv[n - r];
	ans %= MOD;
	ans *= inv[r];
	ans %= MOD;
	return ans;
}


void solve() {
	int n, m;
	cin >> n >> m;
	int ans = 0;
	vector<int> pre(m + 1);
	for(int i = 1; i <= m; i++){
		pre[i] = ncr(i, n - 2);
		pre[i] += pre[i - 1];
		pre[i] %= MOD;
	}

	for(int i = n - 2; i <= m; i++){
		int num = max(0ll, m - 2 * i + 1);
		int val = ncr(i - 1, n - 2);
		num *= val;
		num %= MOD;

		int right = max(i + 1, m - i + 2);
		int x = max(0ll, m - right);
		int sum = (pre[x] - pre[0] + MOD) % MOD;
		num += sum;
		num %= MOD;
		ans += num;
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