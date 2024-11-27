

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
const ll INF = 1e18;

#define int long long 

void solve() {
	int n, m, q;
	cin >> n >> m >> q;

	vector<vector<pair<int,int>>> g(n);
	for(int i = 1; i <= m; i++){
		int a, b, c;	
		cin >> a >> b >> c;
		a--;
		b--;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	vector<vector<int>> dp(n, vector<int>(n, INF));

	for(int i = 0; i < n; i++){
		dp[i][i] = 0;
		for(auto x: g[i]){
			dp[i][x.first] = min(dp[i][x.first], x.second);
		}
		
	}

	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}

	for(int i = 1; i <= q; i++){
		int x, y;
		cin >> x >> y;
		debug(x, y);
		x--;
		y--;
		if(dp[x][y] == INF){
			cout << "-1\n";
			continue;
		}
		cout << dp[x][y] << "\n";
	}
	cout << '\n';
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