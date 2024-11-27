

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
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> a[i][j];
    	}
    }

    vector<vector<int>> dp(n, vector<int>(m));
    int g = gcd(a[0][0], a[n - 1][m - 1]);
    function<int(int)> is_possible = [&](int val){
    	if(a[n - 1][m - 1] % val != 0)
			return 0;
		dp[n - 1][m - 1] = 1;
		for(int i = n - 1; i >= 0; i--){
			for(int j = m - 1; j >= 0; j--){
				if(i != n - 1 || j != m - 1)
					dp[i][j] = 0;
				if(a[i][j] % val != 0)
					continue;
				if(j + 1 < m){
					dp[i][j] |= dp[i][j + 1];
				}
				if(i + 1 < n){
					dp[i][j] |= dp[i + 1][j];
				}
			}
		}
		return dp[0][0];
    };
    int ans = 1;
    for(int j = 1; j * j <= g; j++){
    	if(g % j == 0){
    		if(is_possible(j))
    			ans = max(ans, j);
    		if(j * j != g)
    			if(is_possible(g / j))
    				ans = max(ans, g / j);
    	}
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