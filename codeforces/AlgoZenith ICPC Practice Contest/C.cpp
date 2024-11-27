

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
	string s1, s2;
	cin >> s1 >> s2;
	string s3 = s1 + s2;
	int n = s1.size();
	int m = s2.size();
	int sz = n + m;
	vector<vector<int>> dp(sz, vector<int>(sz, -1));
	function<int(int,int)> dfs = [&](int i, int j){
		if(dp[i][j] != -1){
			return dp[i][j];
		}
		if(j < i){
			return dp[i][j] = 0;
		}
		int x = 0;
		if(s3[i] == s3[j]){
			if(i == j)
				x = max(x, 1 + dfs(i + 1, j - 1));
			else 
				x = max(x, 2 + dfs(i + 1, j - 1));
		}
		x = max(x, dfs(i + 1, j));
		x = max(x, dfs(i, j - 1));
		return (dp[i][j] = x);
	};

	int ans = 0;


	for(int i = 0; i < n; i++){
		for(int j = n; j < sz; j++){
			if(s3[i] == s3[j]){
				ans = max(ans, 2 + dfs(i + 1, j - 1));
			}
		}
	}

	cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}