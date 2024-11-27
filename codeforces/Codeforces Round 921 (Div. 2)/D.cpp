

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

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}

int fact[MAX_N];
int invfact[MAX_N];

void preprocess(){
	fact[0] = 1;
	invfact[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fact[i] = (i * fact[i - 1]) % MOD;
		invfact[i] = modinverse(fact[i]);
	}
}

int ncr(int n, int r){
	int x = fact[n];
	x *= invfact[r];
	x %= MOD;
	x *= invfact[n - r];
	x %= MOD;
	return x;
}


void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int sum = 0;
	for(int i = 0; i < m; i++){
		int u, v, f;
		cin >> u >> v >> f;
		sum += f;
		sum %= MOD;
	}


	int val = ncr(n, 2);
	int prb = binpow(val, k);

	int x1sum = 0;
	int x2sum = 0;

	for(int i = 1; i <= k; i++){	
		int times = ncr(k, i);
		int temp = binpow(val - 1, k - i);
		times *= temp;
		times %= MOD;

		int t1sum = i * times;
		t1sum %= MOD;

		int t2sum = i * (i - 1);
		t2sum %= MOD;
		t2sum *= modinverse(2);
		t2sum %= MOD;

		t2sum *= times;
		t2sum %= MOD;

		x1sum += t1sum;
		x1sum %= MOD;
		x2sum += t2sum;
		x2sum %= MOD;
	}

	x2sum *= m;
	x2sum %= MOD;

	sum *= x1sum;
	sum %= MOD;
	sum += x2sum;
	sum %= MOD;

	sum *= modinverse(prb);
	sum %= MOD;

	cout << sum << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    preprocess();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}