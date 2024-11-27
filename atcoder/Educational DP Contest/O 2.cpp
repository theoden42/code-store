

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
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }  

    vector<vector<int>> dp(n + 1, vector<int> (1 << n, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        int x = i - 1;
        for(int j = (1 << n); j >= 0; j--){
            if(__builtin_popcount(j) != x)continue;
            for(int k = 1; k <= n; k++){
                if(a[i][k] == 1 && !(j & (1 << (k - 1)))){
                    dp[i][j | (1 << (k - 1))] = (dp[i][j | (1 << (k - 1))] + dp[i - 1][j]) % MOD;
                }
            }
        }
    }

    cout << dp[n][(1 << n) - 1] << "\n";
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