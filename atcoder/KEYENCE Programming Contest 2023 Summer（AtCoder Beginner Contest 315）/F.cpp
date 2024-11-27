

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

#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> c(n);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	c[i] = {x, y};
    }
    vector<vector<long double>> dp(n + 1, vector<long double> (33, INF));

    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j <= 32; j++){
    		for(int k = 0; j + k <= 32; k++){	
    			if(i + 1 + k < n){
    				int ind = i + 1 + k;
    				int dx = c[ind][0] - c[i][0];
    				int dy = c[ind][1] - c[i][1];

    				long double dist = sqrtl(dx * dx + dy * dy);
    				long double newvalue = dp[i][j] + dist;

    				if(j != 0)
    					newvalue -= (1ll << (j - 1));
    				if(j + k != 0)
    					newvalue += (1ll << (j + k - 1));

    				dp[ind][j + k] = min(dp[ind][j + k], newvalue);
    			}
    		}
    	}
    }
    long double ans = INF;
    for(int j = 0; j <= 32; j++){
    	ans = min(ans, dp[n - 1][j]);
    }
    cout << setprecision(20) << ans << "\n";
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