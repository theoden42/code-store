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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }

    vector<array<int,2>> dp(n + 1, {(int)1e9, (int)1e9});
    dp[1][0] = 0, dp[1][1] = 0;
    for(int i = 2; i <= (n + 1) / 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int pl = a[i - 1], pr = a[n - i + 2];
                int cl = a[i], cr = a[n - i + 1];
                if(j & 1)
                    swap(pl, pr);
                if(k & 1)
                    swap(cl, cr);
                dp[i][k] = min(dp[i][k], dp[i - 1][j] + (pl == cl) + (cr == pr));
            }
        }
    }


    int ans = min(dp[(n + 1) / 2][0], dp[(n + 1) / 2][1]);
    if(n % 2 == 0 && a[n / 2] == a[n + 1 - n / 2])
        ans += 1;
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