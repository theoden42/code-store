
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
    vector<string> s(h);
    for(int i = 0; i < h; i++){
    	cin >> s[i];
    }
    vector<vector<char>> g(h, vector<char> (w , 0));
    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		g[i][j] = s[i][j];
    	}
    }

    vector<vector<ll>> dp(h + 1, vector<ll> (w + 1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= h; i++){
    	for(int j = 1; j <= w; j++){
    		if(g[i - 1][j - 1] == '#'){
    			continue;
    		}
    		if(i == 1 && j == 1){
    			dp[i][j] = 1;
    		}
    		else
    		dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;

    	}
    }
    cout << dp[h][w] << "\n";
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