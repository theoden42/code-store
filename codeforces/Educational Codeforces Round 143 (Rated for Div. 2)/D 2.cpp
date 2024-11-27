

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

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}


int ncr(int n, int r){
	int sum = 1;
	for(int i = n; i >= n - r + 1; i--){
		sum = (sum * i) % MOD;
	}
	for(int i = 1; i <= r; i++){
		sum = (sum * modinverse(i)) % MOD;
	}
	return sum;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int ans = ncr(n / 3, n / 6);


    for(int i = 0; i < n; i += 3){
    	int x = a[i];
    	int y = a[i + 1];
    	int z = a[i + 2];
    	int mx = min({x, y, z});
    	// debug(mx);
    	int c = 0;
    	if(x == mx)c++;
    	if(y == mx)c++;
    	if(z == mx)c++;
    	// debug(c, x, y, z);
    	ans = (ans * c) % MOD;
    }
    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}