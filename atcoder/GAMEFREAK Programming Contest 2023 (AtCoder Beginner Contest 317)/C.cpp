

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
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}

	vector<vector<int>> dp(n, vector<int>(1 << 10 + 1, -1));

	function<int(int, int)> find = [&](int source, int mask){
		if(dp[source][mask] != -1){
			return dp[source][mask];
		}
		int mx = 0;
		for(auto [n, w]: adj[source]){
			if(mask >> n & 1)
				continue;

			int nwmask = (mask | (1 << n));
			mx = max(mx, w + find(n, nwmask));
		}
		return dp[source][mask] = mx;
	};


	int mxans = 0;
	for(int i = 0; i < n; i++){

		for(int i = 0; i < n; i++){
			for(int j = 0; j <= 1 << 10; j++){
				dp[i][j] = -1;
			}
		}
		int mask = (1 << i);
		int ans = find(i, mask);
		mxans = max(mxans, ans);
	}
	cout << mxans << "\n";
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