

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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[n][m] = 1;

    for(int i = n - 1; i >= 0; i--){
    	for(int j = 0; j < m - 1; j++){
    		if(s[i] != s[j])
    			continue;
    		dp[i][j] |= dp[i + 1][j + 1];
    		dp[i][j] |= dp[i + 1][0];
    	}
    	if(s[i] != t.back())
    		continue;
    	for(int j = 0; j <= m; j++){
    		if(j <= i + 1)
    			dp[i][m - 1] |= dp[i + 1][j];
    	}
    }

    // debug(dp);

    if(dp[0][0]){
    	cout << "Yes\n";
    } else {
    	cout << "No\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}