

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

const int MAX_N = 4e6 + 5;
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


vector<int> fac(MAX_N + 1);
vector<int> invfac(MAX_N + 1);
void pre(){
	fac[0] = 1;
	for(int i = 1; i <= MAX_N; i++){
		fac[i] = fac[i - 1];
		fac[i] *= i;
		fac[i] %= MOD;
		invfac[i] = modinverse(fac[i]);
	}
}

int ways(int r, int n){
	int x = fac[n + r - 1];
	x *= modinverse(fac[n]);
	x %= MOD;
	x *= modinverse(fac[r - 1]);
	x %= MOD;
	return x;
}

void solve() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;

    if(c1 != c2 && c1 != c2 - 1 && c2 != c1 - 1){
    	cout << "0\n";
    	return;
    }	

    if(c1 == 0 && c2 == 0){
    	if(c3 == 0 || c4 == 0){
    		cout << "1\n";
    		return;
    	} else {
    		cout << "0\n";
    		return;
    	}
    }


    if(c1 == c2){
    	int ans = 0;	
    	int w1 = ways(c1 + 1, c4);
    	w1 %= MOD;
    	w1 *= ways(c1, c3);
    	w1 %= MOD;

    	int w2 = ways(c1 + 1, c3);
    	w2 %= MOD;
    	w2 *= ways(c1, c4);
    	w2 %= MOD;

    	ans += w1;
    	ans %= MOD;
    	ans += w2;
    	ans %= MOD;
    	cout << ans << "\n";
    } else {
    	int sp = max(c1, c2);
    	int w1 = ways(sp, c3);
    	w1 *= ways(sp, c4);
    	w1 %= MOD;
    	cout << w1 << "\n";
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