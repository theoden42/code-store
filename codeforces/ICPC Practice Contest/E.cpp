

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
    int r, c, n;
    cin >> r >> c >> n;
    vector<vector<int>> grid(r, vector<int>(c, 0));
    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		cin >> grid[i][j];
    	}
    }

    auto is_pass = [&](int i, int j){
    	if(i > 0 && j > 0 && i < r - 1 && j < c - 1){
    		if(grid[i + 1][j] == -1 || grid[i - 1][j] == -1 || grid[i][j + 1] == -1 || grid[i][j - 1] == -1)
    			return false;
    		return (
    			grid[i][j] < grid[i + 1][j] 
    			&& grid[i][j] < grid[i - 1][j] 
    			&& grid[i][j] > grid[i][j - 1] 
    			&& grid[i][j] > grid[i][j + 1]
    			);
    	} else {
    		return false;
    	}
    };

    vector<vector<vector<int>>> dp(c, 
    	vector<vector<int>>(r, 
    		vector<int>(n + 2, 1e18)));

    for(int j = 0; j < r; j++){
    	if(grid[j][0] == -1)
    		continue;
    	if(is_pass(j, 0)){
    		dp[0][j][1] = grid[j][0];
    	} else {
    		dp[0][j][0] = grid[j][0];
    	}
    }

    // debug(dp[1]);

    for(int i = 0; i < c - 1; i++){
    	for(int j = 0; j < r; j++){	
    		for(int k = 0; k <= n; k++){
    			if(dp[i][j][k] == 1e18)
    				continue;
    			if(j - 1 >= 0 && grid[j - 1][i + 1] != -1){
    				if(is_pass(j - 1, i + 1))
    					dp[i + 1][j - 1][k + 1] = 
    							min(dp[i][j][k] + grid[j - 1][i + 1], dp[i + 1][j - 1][k + 1]);
    				else 
    					dp[i + 1][j - 1][k] = 
    							min(dp[i][j][k] + grid[j - 1][i + 1], dp[i + 1][j - 1][k]);
    			}
    			if(grid[j][i + 1] != -1){
    				if(is_pass(j, i + 1))
    					dp[i + 1][j][k + 1] = 
    							min(dp[i][j][k] + grid[j][i + 1], dp[i + 1][j][k + 1]);
    				else 
    					dp[i + 1][j][k] = 
    							min(dp[i][j][k] + grid[j][i + 1], dp[i + 1][j][k]);
    			} 
    			if(j + 1 < r && grid[j + 1][i + 1] != -1){
    				if(is_pass(j + 1, i + 1))
    					dp[i + 1][j + 1][k + 1] = 
    							min(dp[i][j][k] + grid[j + 1][i + 1], dp[i + 1][j + 1][k + 1]);
    				else 
    					dp[i + 1][j + 1][k] = 
    						min(dp[i][j][k] + grid[j + 1][i + 1], dp[i + 1][j + 1][k]);
    			}
    		}
    	}
    }
    // debug(dp[0], dp[1]);
    int mn = 1e18;
    for(int j = 0; j < r; j++){
    	mn = min(mn, dp[c - 1][j][n]);
    }

    if(mn == 1e18){
    	cout << "impossible\n";
    } else {
    	cout << mn << "\n";
    }
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