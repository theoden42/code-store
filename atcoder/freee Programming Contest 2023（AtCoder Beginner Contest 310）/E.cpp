

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

#define int int64_t

vector<vector<int>> dp;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++){
    	a[i + 1] = s[i] - '0';
    }

    dp.assign(n + 1, vector<int> (2, 0));

    int ans = 0;

    dp[n][0] = 0;
    dp[n][1] = 1;

    if(a[n] == 1)
        ans = 1;
    

    for(int i = n - 1; i >= 1; i--){
    	dp[i][0] = dp[i + 1][1];

    	if(a[i + 1] == 0){
    		dp[i][1] = 1 + dp[i + 1][1];
    	}
    	else{
    		dp[i][1] = 1 + dp[i + 1][0];
    	}

    	if(a[i] == 1){
    		ans += dp[i][1];
    	}else{
    		ans += dp[i][0];
    	}
    }

    debug(dp);

    cout << ans << "\n";

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