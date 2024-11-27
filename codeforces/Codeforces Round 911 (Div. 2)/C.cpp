

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
	string s;
	cin >> s;
	vector<vector<int>> childs(n);
	for(int i = 0; i < n; i++){
		int l, r;
		cin >> l >> r;
		childs[i] = {l - 1, r - 1};
	}

	vector<int> dp(n, -1);
	function<int(int)> dfs = [&](int source){
		if(dp[source] != -1)
			return dp[source];

		if(childs[source][0] == -1 && childs[source][1] == -1)
			return dp[source] = 0;

		if(s[source] == 'U'){
			int val = 1e9;
			if(childs[source][0] != -1){
				val = min(val, 1 + dfs(childs[source][0]));
			} 
			if(childs[source][1] != -1){
				val = min(val, 1 + dfs(childs[source][1]));
			}
			return dp[source] = val;
		} else if(s[source] == 'L'){
			int val = 1e9;
			if(childs[source][0] != -1){
				val = min(val, dfs(childs[source][0]));
			} 
			if(childs[source][1] != -1){
				val = min(val, 1 + dfs(childs[source][1]));
			}
			return dp[source] = val;
		} else {
			int val = 1e9;
			if(childs[source][0] != -1){
				val = min(val, 1 + dfs(childs[source][0]));
			} 
			if(childs[source][1] != -1){
				val = min(val, dfs(childs[source][1]));
			}
			return dp[source] = val;
		}
	};
	dfs(0);
	cout << dp[0] << "\n";
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