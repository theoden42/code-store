

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    sort(all(a));
    vector<int> prefix(n + 1);
    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1] + a[i - 1];
    }

    int ind = 1;

    for(int i = 1; i <= n; i++){


    	int req = i * a[i - 1] - prefix[i];

    	if(req > k){
    		break;
    	}
    	else{
    		ind = i;
    	}
    }

    int x = ind * a[ind - 1] - prefix[ind];
    int rem = k - x;

    for(int i = 0; i < ind; i++){
    	a[i] = a[ind - 1];
    }

    for(int i = 0; i < ind; i++){
    	a[i] += rem / ind;
    }

    for(int i = 0; i < rem % ind; i++){
    	a[i] += 1;
    }


    ll sum = 0;
    for(int i = 0; i < n; i++){
    	sum += (a[i]);
    	sum %= MOD;
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
    	int val = (a[i] * (sum - a[i] + MOD) % MOD) % MOD;
    	val = (val * modinverse(2)) % MOD;
    	ans += val;
    	ans %= MOD;
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}