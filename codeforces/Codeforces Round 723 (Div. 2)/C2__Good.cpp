

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(1e5 + 5, -1));
    dp[0][0] = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 1e5 + 5; j++){
    		if(dp[i][j] == -1)
    			continue;
    		dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
    		if(j + a[i] >= 0 && j + a[i] < 1e5 + 5){
    			dp[i + 1][j + a[i]] = max(dp[i + 1][j + a[i]], dp[i][j] + 1);
    		}
    	}
    }
    int mx = 0;
    for(int j = 0; j < 1000; j++){
    	mx = max(mx, dp[n][j]);
    }
    cout << mx << "\n";
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