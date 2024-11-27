

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n + 1), pref2(n + 1);
    for(int i = 2; i <= n; i++){
    	pref[i] = (s[i - 1] != s[i - 2]);
    	pref[i] += pref[i - 1];
    }
    for(int i = 1; i <= n; i++){
    	pref2[i] += pref[i];
    	pref2[i] += pref2[i - 1]; 
    }
    vector<int> dp(n + 1);
    dp[1] = 0;
    for(int i = 2; i <= n; i++){
    	if(s[i - 1] != s[i - 2]){
    		int lsum = ((i * (i - 1)) / 2) % MOD;
    		int nsum = (((dp[i - 1] + lsum) % MOD - i + MOD) % MOD + 1) % MOD;
    		dp[i] = nsum;
    	} else {
    		int csum = (i - 1) * pref[i - 1] - pref2[i - 1];
    		int nsum = (dp[i - 1] + csum) % MOD;
    		dp[i] = nsum;
    	}
    }

    // debug(dp);

    int ans = 0;
    for(int i = 1; i <= n; i++){
    	ans += dp[i];
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