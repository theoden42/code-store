

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

int get(int i, int j, vector<int>& a, vector<vector<int>>& dp){
	if(i >= j){
		return 0;
	}

	if(dp[i][j] != -1)return dp[i][j];

	int x = a[i];
	int v1 = get(i + 2, j, a, dp);
	int v2 = get(i + 1, j - 1, a, dp);

	dp[i][j] = x + min(v1, v2);

	int y = a[j];
	v1 = get(i, j - 2, a, dp);
	v2 = get(i + 1, j - 1, a, dp);

	dp[i][j] = max(dp[i][j], y + min(v1, v2));

	return dp[i][j];

}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int>(n, -1));
	int val = get(0, n - 1, a, dp);

	cout << val << "\n";
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