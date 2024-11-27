
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
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> g(h, vector<int> (w, 0));
    for(int i = 0; i < n; i++){
    	int r, c;
    	cin >> r >> c;
    	r--;
    	c--;
    	g[r][c] = 1;
    }
    vector<vector<ll>> dp(h, vector<ll>(w, 0));
   	dp[0][0] = 1;
   	for(int j = 1; j < h; j++){
   		if(g[j][0] != 1){
   			dp[j][0] += dp[j - 1][0];
   		}
   	}
   	for(int i = 1; i < w; i++){
   		if(g[0][i] != 1){
   			dp[0][i] += dp[0][i - 1];
   		}
   	}
   	for(int i = 1; i < h; i++){
   		for(int j = 1; j < w; j++){
   			if(g[i][j] == 1){
   				continue;
   			}
   			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%MOD;
   		}
   	}
   	cout << dp[h - 1][w  - 1] << "\n";
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