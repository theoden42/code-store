

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

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	map<int,vector<int>> mpa, mpb;
	for(int i = 0; i < n; i++){
		mpa[a[i]].push_back(i);
	}
	for(int j = 0; j < m; j++){
		mpb[b[j]].push_back(j);
	}
	vector<vector<vector<int>>>
	 dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1e9)));
	dp[0][0][0] = dp[0][0][1] = 0;

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++) {
			if(i != n && dp[i][j][0] != -1e9){
				dp[i + 1][j][0] 
				= max(dp[i + 1][j][0], dp[i][j][0] + a[i]);
				auto a_ind = lower_bound(all(mpb[a[i]]), j);
				if(a_ind != mpb[a[i]].end()){
					dp[i + 1][*a_ind + 1][1] 
					= max(dp[i][*a_ind + 1][1], dp[i][j][0] + a[i]);
				}
			}
			if(j != m && dp[i][j][1] != -1e9){
				dp[i][j + 1][1] = max(dp[i][j + 1][1], dp[i][j][1] + b[j]);
				auto b_ind = lower_bound(all(mpa[b[j]]), i);
				if(b_ind != mpa[b[j]].end()){
					dp[*b_ind + 1][j + 1][0] 
					= max(dp[*b_ind + 1][j + 1][0], dp[i][j][1] + b[j]);
				}
			} 
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			ans = max({ans, dp[i][j][0], dp[i][j][1]});
		}
	}
	cout << ans << "\n";
}