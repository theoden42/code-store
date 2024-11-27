

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
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[0][0] = 0;

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 2; j++){

    		int vt;
    		if(j == 0 && x[i] == 0)
    			vt = 0;
    		if(j == 0 && x[i] == 1)
    			vt = 1;
    		if(j == 1 && x[i] == 0)
    			vt = 0;
    		if(j == 1 && x[i] == 1)
    			vt = 2;

	    	if(vt <  2)
    			dp[i + 1][vt] = max(dp[i + 1][vt], dp[i][j] + y[i]);

    		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    	}
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

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