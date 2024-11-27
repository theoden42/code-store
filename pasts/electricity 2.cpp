
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


int dfs1(int source, vector<int>& cap, vector<vector<int>>& g, vector<int>& dp){
	if(dp[source] != -1){
		return dp[source];
	}
	int mx = 1;
	for(auto& x: g[source]){
		if(cap[x] < cap[source]){
			mx += dfs1(x, cap, g, dp);
		}
	}
	dp[source] = mx;
	return mx;
}

void solve() {
   	int n;
   	cin >> n;
   	vector<int> a(n);
   	for(int i = 0; i < n; i++){
   		cin >> a[i];
   	}
   	vector<vector<int>> g(n);
   	for(int i = 0; i < n - 1; i++){
   		int x, y;
   		cin >> x >> y;
   		x--;
   		y--;
   		g[x].push_back(y);
   		g[y].push_back(x);
   	}
   	int mx = 0;
   	vector<int> dp(n, -1);

   	for(int i = 0; i < n; i++){
   		mx = max(mx, dfs1(i, a, g, dp));
   	}
   	debug(dp);
   	cout << mx << "\n";		

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}