
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

int dfs(int source, vector<int> g[], vector<int>& dp){
    // cout << source << " " << dp[source] << "\n";
	if(dp[source] != -1){
        return dp[source];
    }
	int m = 0;
	for(auto& x: g[source]){
		m = max(m, 1 +  dfs(x, g, dp));
	}
	dp[source] = m;
    // cout << source << " " << dp[source] << "\n";
	return m;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n];
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	g[x].push_back(y);
    }
    vector<int> dp(n, -1);
    for(int i = 0; i < n; i++){
    	//from all the vertexes i find the longest path
    	if(dp[i] != -1){
    		continue;
    	}
    	dp[i] = dfs(i, g, dp);
    }
    int l = 0;
    for(auto x: dp){
    	// cout << x << " ";
    	l = max(l, x);
    }
    // cout << "\n";
    cout << l << "\n";
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