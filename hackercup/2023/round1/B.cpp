/* author: (g)theoden42 */
#pragma GCC optimize("Ofast")

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

void findans(int sum, int prod, vector<vector<int>>& dp, vector<int>& ans){
	if(sum == 0){
		return;
	}
	int mnvalues = 1e18;
	int ansval = 0;
	for(int k = 1; k <= 41; k++){
		if(sum - k >= 0 && prod % k == 0 && dp[sum - k][prod / k] != 1e18) {
			if(dp[sum - k][prod / k] < mnvalues) {
				mnvalues = dp[sum - k][prod / k];
				ansval = k;
			}
		}
	}

	if(ansval != 0){
		ans.push_back(ansval);
		findans(sum - ansval, prod / ansval, dp, ans);
	}
}

void solve() {
	int p;
	cin >> p;
	vector<int> v;
	int max_values = (1ll << 21);
	if(p >= max_values) { 
		cout << "-1\n";
		return;
	}

	vector<vector<int>> dp(42, vector<int>(p + 1, 1e18));
	dp[0][1] = 0;

	for(int i = 0; i <= 41; i++){
		for(int j = 0; j <= p; j++){
			for(int k = 1; k <= 41; k++){
				if(j % k == 0 && i - k >= 0) { 
					dp[i][j] = min(dp[i][j], 1 + dp[i - k][j / k]);
				}
			}
		}
	}

	if(dp[41][p] == 1e18) { 
		cout << "-1\n";
		return;
	}
	vector<int> ans;	
	findans(41, p, dp, ans);

	cout << ans.size() << " ";
	for(auto a: ans) {
		cout << a << " ";
	}
	cout << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}