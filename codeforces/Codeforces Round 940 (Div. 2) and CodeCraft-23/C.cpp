

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

vector<int> fac(MAX_N);
vector<int> inv(MAX_N);

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
	vector<int> v(n + 1);

	for(int i = 0; i < k; i++){
		int r, c;
		cin >> r >> c;
		v[r] = 1;
		v[c] = 1;
	}

	int count = 0;
	for(int i = 1; i <= n; i++){
		if(v[i] == 0)
			count += 1;
	}

	int ans = 0;
	for(int i = 0; i <= count; i++){
		int rem = count - i;
		if(rem & 1)
			continue;

		rem /= 2;
		int temp = ncr(count, i);
		int pair = fac[2 * rem];
		pair %= MOD;

		pair *= inv[rem];
		pair %= MOD;

		pair *= temp;
		pair %= MOD;

		ans += pair;
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