

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

ll binpow(ll a, ll b, ll m = MOD)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b = b >> 1; 
    }
    return (ans % m);
}

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
    int n;
    cin >> n;
     vector<int> p(n);
     vector<int> k(n);
     for(int i = 0; i < n; i++){
     	cin >> p[i] >> k[i];
     }
     int divcount = 1;
     for(int i = 0; i < n; i++){
     	divcount *= (k[i] + 1);
     	divcount %= MOD;
     }

     int divsum = 1;
     int currsum = 1;
	 for(int i = 0; i < n; ++i){
	 	int temp = binpow(p[i], k[i] + 1);
	 	temp -= 1;
	 	temp += MOD;
	 	temp %= MOD;

	 	temp *= modinverse(p[i] - 1);
	 	temp %= MOD;

	 	divsum *= temp;
	 	divsum %= MOD;
	 }

     int divprod = 1;
     int num = 1;
     for(int i = 0; i < n; i++){
        int x = k[i];
        x *= (k[i] + 1);
        x /= 2;
        x %= MOD - 1;
        divprod = binpow(divprod, k[i] + 1);
        x = binpow(p[i], x);
        x = binpow(x, num);
        divprod *= x;
        divprod %= MOD;
        num *= (k[i] + 1);
        num %= (MOD - 1);
     }

	 cout << divcount << " " << divsum << " " << divprod << "\n";
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