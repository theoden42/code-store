

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
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i++){
		int a;
		cin >> a;
		adj[i].push_back(a);
		adj[a].push_back(i);
	}

	string s;
	cin >> s;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; i++){
		if(s[i - 1] == 'P'){
			v[i] = 0;
		} else if(s[i - 1] == 'S'){
			v[i] = 1;
		} else {
			v[i] = 2;
		}
	}

	vector<vector<int>> dp(n + 1, vector<int>(2, -1));

	function<int(int, int, int)> dfs = [&](int source, int parent, int value){
		if(dp[source][value] != -1)
			return dp[source][value];

		int sum = 0;
		for(auto x: adj[source]){
			if(x == parent)
				continue;

			if(v[x] == 2){
				int mx = 1e9;
				for(int j = 0; j < 2; j++){
					int val = ((j == value) ? dfs(x, source, j) : 1 + dfs(x, source, j));
					mx = min(mx, val);
				}

				sum += mx;
			} else if(v[x] == value)
				sum += dfs(x, source, v[x]);
			else 
				sum += 1 + dfs(x, source, v[x]);
		}

		return dp[source][value] = sum;
	};

	dfs(1, -1, 0);
	dfs(1, -1, 1);
	int ans = 0;

	if(v[1] == 2){
		ans = min(dp[1][0], dp[1][1]);
	} else {
		ans = dp[1][v[1]];
	}

	cout << ans << "\n";
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