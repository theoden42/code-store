

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }

    int dp[n + 1][n + 1][2];
    int ndp[n + 1][n + 1][2];
    for(int i = 0; i <= n; i++){
    	for(int j = 0; j <= n; j++){
    		for(int k = 0; k < 2; k++){
    			dp[i][j][k] = -1;
    			ndp[i][j][k] = -1;
    		}
    	}
    }

    dp[0][0][0] = 0;

    for(int i = 0; i < n; i++){	
    	for(int i = 0; i <= n; i++){
	    	for(int j = 0; j <= n; j++){
	    		for(int k = 0; k < 2; k++){
	    			ndp[i][j][k] = -1;
	    		}
	    	}
	    }
    	for(int k = 0; k <= n; k++){
    		for(int j = 0; j <= n; j++){
    			for(int l = 0; l < 2; l++){
    				if(dp[k][j][l] == -1)
    					continue;
    				if(j <= a[i]){
    					ndp[k][a[i]][0] = max(ndp[k][a[i]][0], dp[k][j][l] + 1);
    				}
    				if(l){
    					ndp[k][j][1] = max(ndp[k][j][1], dp[k][j][l]);
    				}
    				if(k < n){
    					ndp[k + 1][j][1] = max(ndp[k + 1][j][1], dp[k][j][l]);	
    				}
    			}
    		}
    	}
    	// debug(ndp);
		for(int k = 0; k <= n; k++){
			for(int j = 0; j <= n; j++){
				dp[k][j][0] = ndp[k][j][0];
				dp[k][j][1]	= ndp[k][j][1];
			}
		}
    }

    int mn = INF;
    for(int last = 1; last <= n; last++){
    	for(int b = 0; b < 2; b++){
    		int val = n - ndp[0][last][b];	
    		mn = min(mn, val);
    	}
    }
    for(int k = 1; k <= n; k++){
    	for(int last = 1; last <= n; last++){
    		for(int b = 0; b < 2; b++){
    			int val = n - ndp[k][last][b];
    			mn = min(mn, val);
    		}
    	}
    	cout << mn << " ";
    }

    cout << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}