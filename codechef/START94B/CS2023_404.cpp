

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> dp(n + 1, vector<int>(4, 0));

    dp[0][0] = 1;
    int count = 0;

    for(int i = 1; i <= n; i++){
        char x = s[i - 1];
        char ch;

        int times = ((x  == '*')? 2 : 1);

        for(int k = 1; k <= times; k++){

            if(x != '*')
                ch = x;
            else{
                if(k == 1){
                    ch = '4';
                }
                else{
                    ch = '0';
                }
            }

            for(int j = 0; j < 4; j++){
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }

            if(ch == '4'){
                dp[i][1] += dp[i - 1][0];
                dp[i][1] %= MOD;
                dp[i][3] += dp[i - 1][2];
                dp[i][3] %= MOD;
            }
            else if(ch == '0'){
                dp[i][2] += dp[i - 1][1];
                dp[i][2] %= MOD;
            }
        }

    }

    // debug(dp);

    cout << dp[n][3] << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}