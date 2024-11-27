

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
const ll INF = 1e18;

#define int long long

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int i = n - 1; i >= 0; i--)
    	for(int j = 0; j < 2; j++){
    		int mn = INF;
    		if(j){
    			if(s[i] == 'A'){
    				mn = min(mn, dp[i + 1][j] + x);
    				mn = min(mn, dp[i + 1][0] + z + y);
    			} else {
    				mn = min(mn, dp[i + 1][1] + y);
    				mn = min(mn, dp[i + 1][0] + z + x);
    			}
    		} else{
    			if(s[i] == 'A'){
    				mn = min(mn, dp[i + 1][j] + y);
    				mn = min(mn, dp[i + 1][1] + z + x);
    			} else {
    				mn = min(mn, dp[i + 1][0] + x);
    				mn = min(mn, dp[i + 1][1] + z + y);
    			}
    		}
    		dp[i][j] = mn;
    	}
    cout << dp[0][0] << "\n";
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