

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
const ll INF = 1e18;

#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> prefix(n + 1, 0);
    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1] + a[i - 1];
    }


    vector<vector<int>> dp(n, vector<int> (n, INF));

    for(int i = 0; i < n; i++){
        dp[i][i] = 0;
    }

    for(int l = 2; l <= n; l++){
        for(int i = 0; i <= n - l; i++){
            int j = i + l - 1;
            for(int k = i; k < j; k++){
                int x = prefix[k + 1] - prefix[i];
                int y = prefix[j + 1] - prefix[k + 1];
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + x + y);
            }
        }
    }
    cout << dp[0][n - 1];

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}