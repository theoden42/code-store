

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

int get(int ind1, int ind2, string& x, string& y, vector<vector<int>>& dp){
	int n = dp.size();
	int m = dp[0].size();
	if(ind2 == m)
		return 1;

	if(ind1 == n)
		return 0;

	if(x[ind1] == y[ind2])
}

void solve() {
	string x, t;
	cin >> x >> t;
	int n = x.size();
	int m = t.size();
	vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
	int ans = get(0, 0, x, t, dp);
	if(ans){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
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