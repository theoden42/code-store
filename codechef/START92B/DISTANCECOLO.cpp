

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


vector<int> factorial(205);


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


void pre(){
	factorial[0] = 1;
	for(int i = 1; i <= 204; i++){
		factorial[i] = (i * factorial[i - 1]) % MOD;
	}
}

int ncr(int n, int r){
	int x = factorial[n];
	x = (x * modinverse(factorial[r])) % MOD;
	x = (x * modinverse(factorial[n - r])) % MOD;
	return x % MOD;
}

void solve() {
    int n, k;
    cin >> n >> k;

    if(n >= k){
    	cout << factorial[k] << "\n";
    }
    else{
    	int chose = (ncr(k, n) * factorial[n]) % MOD;
    	cout << chose << "\n";
    }

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