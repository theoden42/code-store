

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

int f(int index, int totsum, int sum, vector<int>& a, vector<vector<int>>& dp){
	int n = a.size();
	if(index == n){
		return abs(sum - (totsum - sum));

	}
	if(dp[index][sum] != -1)
		return dp[index][sum];

	int mn = f(index + 1, totsum + a[index], sum, a, dp);
	mn = min(mn, f(index + 1, totsum + a[index], sum + a[index], a, dp));
	return dp[index][sum] = mn;
}

int mndif(vector<int>& a){
	int n = a.size();
	int sum = accumulate(all(a), 0ll);
	vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	return f(0, 0, 0, a, dp);
}
void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for(int i = 2; i <= n; i++){
		int u;
		cin >> u;
		adj[u].push_back(i);
		adj[i].push_back(u);
	}

	vector<int> size(n + 1);
	function<int(int, int)> dfs1 
	= [&](int source, int parent){
		int count = 1;
		for(auto x: adj[source]){
			if(x == parent)
				continue;
			count += dfs1(x, source);
		}
		size[source] = count;
		return count;		
	};

	dfs1(1, -1);
	int ans = 0;

	function<void(int, int)> dfs2 
	= [&](int source, int parent){
		vector<int> childs;
		for(auto x: adj[source]){
			if(x != parent)
				childs.push_back(size[x]);
		}

		int mn = mndif(childs);
		int sum = accumulate(all(childs), 0ll);
		int x = (sum + mn) / 2;
		int mx = x * (x - mn);
		ans += mx;

		for(auto x: adj[source]){
			if(x != parent){
				dfs2(x, source);
			}
		}
	};

	dfs2(1, -1);
	cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}