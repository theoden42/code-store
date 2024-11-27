

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

void solve() {
    int n, x, z;
    cin >> n >> x >> z;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    vector<int> dp(x, 1e18), ndp(x, 1e18);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < x; j++){
    		ndp[j] = min(ndp[j], dp[j]);
    		int nsum = (j + a[i]) % x;
    		ndp[nsum] = min(ndp[nsum], dp[j] + a[i]);
    	}

    	for(int j = 0; j < x; j++){
    		dp[j] = ndp[j];
    		ndp[j] = 1e18;
    	}
    }

    debug(dp);

    int mx = 1e18;

    for(int i = 0; i < x; i++){
    	if(dp[i] != 1e18 && ((x - i) % x == (z % x))){
    		int val = (z + dp[i]) / x;	
    		mx = min(mx, val);
    	}
    }

    if(mx == 1e18){
    	cout << "-1\n";
    } else {
    	cout << mx << "\n";
    }
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