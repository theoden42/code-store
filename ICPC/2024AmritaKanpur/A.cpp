

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
    vector<int> sz(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> sz[i];
    }
    vector<vector<int>> vals(n + 1);
    vector<gp_hash_table<int,int>> num(n + 1);	
    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < sz[i]; j++){
    		int x;
    		cin >> x;
    		vals[i].push_back(x);
    		num[i][x] += 1;
    	}
    }

    int dp[n + 1][2][2];
    for(int i = 0; i <= n; i++){
    	for(int j = 0; j < 2; j++){
    		for(int k = 0; k < 2; k++){
    			dp[i][j][k] = 1e18;
    		}
    	}
    }
    dp[1][1][1] = 0;
    for(int i = 2; i <= n; i++){
    	for(int j = 0; j < 2; j++){
    		for(int k = 0; k < 2; k++) if(dp[i - 1][j][k] != 1e18){
    			for(int l = 0; l < 2; l++){
    				int count = 0;
    				for(auto v: vals[i]){
    					if(l == 0 && j == 1){
    						count += num[i - 1][v];
    					}
    					if(l == 0 && k == 1){
    						count += num[i - 2][v];
    					}
    				}

    				dp[i][l][j] = min(dp[i][l][j], dp[i - 1][j][k] + count);
    			}
    		}
    	}
    }
    int ans = min(dp[n][0][1], dp[n][0][0]);
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