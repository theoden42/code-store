
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		cin >> grid[i][j];
    	}
    }
    vector<vector<int>> dp(h, vector<int> (w, 0));
    dp[0][0] = 1;
    for(int j = 1; j < w; j++){
    	if(grid[0][j] != '#'){
    		dp[0][j] = dp[0][j - 1];
    	}
    }
    for(int i = 1; i < h; i++){
    	if(grid[i][0] != '#'){
    		dp[i][0] = dp[i - 1][0];
    	}
    }
    for(int i = 1; i < h; i++){
    	for(int j = 1; j < w; j++){
    		if(grid[i][j] == '#'){
    			dp[i][j] = 0;
    			continue;
    		}
    		else{
    			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    		}
    	}
    }
    cout << dp[h - 1][w - 1] << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}