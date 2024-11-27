

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

int dp[301][301][305];
	
void solve() {
    int l, n, m;
    cin >> l >> n >> m;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		for(int k = 0; k <= l; k++){
    			dp[i][j][k] = 0;
    		}
    	}
    }
    vector<int> a(l);
    for(int i = 0; i < l; i++){
    	cin >> a[i];
    }
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> b[i][j];
    	}
    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		dp[i][j][l] = 1;	
    	}
    }
    vector<vector<int>> pref(m, vector<int>(l + 1, 1));
    for(int i = n - 1; i >= 0; i--){
    	vector<int> val(l + 1, 1);
    	for(int j = m - 1; j >= 0; j--){
    		if(j < m - 1){
	    		for(int k = 0; k <= l; k++){
                    val[k] &= pref[j + 1][k];
	    		}
    		}
    		for(int k = 0; k < l; k++){
    			if(a[k] == b[i][j] && val[k + 1]){
    				dp[i][j][k] = 0;	
    			} else if(i < n - 1 && !dp[i + 1][j][k]){
                    dp[i][j][k] = 0;
                } else if(j < m - 1 && !dp[i][j + 1][k]){
                    dp[i][j][k] = 0;
                } else {
                    dp[i][j][k] = 1;
                }
    		}
    	}
        for(int j = m - 1; j >= 0; j--){
            for(int k = 0; k <= l; k++){
                pref[j][k] &= dp[i][j][k];
            }
        }
    }

    if(dp[0][0][0]){
    	cout << "N\n";
    } else {
    	cout << "T\n";
    }
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