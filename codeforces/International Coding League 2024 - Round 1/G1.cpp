

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


vector<int> fac(MAX_N);
vector<int> invfac(MAX_N);

vector<int> value(1005, 1);

void pre(){
	fac[0] = 1;
	invfac[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fac[i] = (i * fac[i - 1]);
		fac[i] %= MOD;
		invfac[i] = modinverse(fac[i]);
	}
}

int ncr(int n, int r){
	int ans = fac[n];
	ans *= invfac[n - r];
	ans %= MOD;
	ans *= invfac[r];
	ans %= MOD;

	return ans;
}

void calc(){
	for(int i = 1; i <= 1000; i++){
		int sum = 0;
		for(int k = 1; k < i; k++){
			int val = ncr(i, k);
			val *= k;
			val %= MOD;
			val *= value[k];
			val %= MOD;
			int pw = ((i - k) * (i - k - 1)) / 2;
			pw = binpow(2, pw);
			val *= pw;
			val %= MOD;

			sum += val;
			sum %= MOD;
		}

		int pw = (i * (i - 1)) / 2;
		pw = binpow(2, pw);
		pw *= i;
		pw %= MOD;

		pw -= sum;
		pw += MOD;
		pw %= MOD;

		pw *= modinverse(i);
		pw %= MOD;

		value[i] = pw;
	}

}



void solve() {
	int n;
	cin >> n;
	int ans = value[n];
	ans += 1;
	ans %= MOD;
	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    pre();
    calc();
    cin >> tc;
    debug(value);
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}