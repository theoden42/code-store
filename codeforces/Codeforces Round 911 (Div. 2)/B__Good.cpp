

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
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<vector<int>>> dp1(301, vector<vector<int>>(301, vector<int>(301, 0)));
    vector<vector<vector<int>>> dp2(301, vector<vector<int>>(301, vector<int>(301, 0)));
    vector<vector<vector<int>>> dp3(301, vector<vector<int>>(301, vector<int>(301, 0)));
    for(int i = 0; i < 301; i++){
    	dp1[0][0][i] = 1;
    	dp2[0][i][0] = 1;
    	dp3[i][0][0] = 1;
    }	
    for(int i = 0; i < 101; i++){
    	for(int j = 0; j < 101; j++){
    		for(int k = 0; k < 101; k++){
    			if(i > 0 && j > 0){
    				dp1[i][j][k] |= dp1[i - 1][j - 1][k + 1];
    				dp2[i][j][k] |= dp2[i - 1][j - 1][k + 1];
    				dp3[i][j][k] |= dp3[i - 1][j - 1][k + 1];
    			} 
    			if(i > 0 && k > 0){
    				dp1[i][j][k] |= dp1[i - 1][j + 1][k - 1];
    				dp2[i][j][k] |= dp2[i - 1][j + 1][k - 1];
    				dp3[i][j][k] |= dp3[i - 1][j + 1][k - 1];
    			}
    			if(j > 0 && k > 0){
					dp1[i][j][k] |= dp1[i + 1][j - 1][k - 1];
    				dp2[i][j][k] |= dp2[i + 1][j - 1][k - 1];
    				dp3[i][j][k] |= dp3[i + 1][j - 1][k - 1];
    			}
    		}
    	}
    }

    cout << dp1[a][b][c] << " " << dp2[a][b][c] << " " << dp3[a][b][c] << "\n";
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