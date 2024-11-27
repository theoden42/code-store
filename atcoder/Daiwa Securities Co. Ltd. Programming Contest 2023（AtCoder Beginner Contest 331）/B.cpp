

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
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    vector<int> dp(145, 1e9);
    dp[0] = 0;
    for(int i = 1; i < 6; i++){
        dp[i] = min({s, m, l});
    }

    for(int i = 0; i <= 144; i++){
    	if(i >= 6){
    		dp[i] = min(dp[i], dp[i - 6] + s);
    	}
    	if(i >= 8){
    		dp[i] = min(dp[i], dp[i - 8] + m);
    	}
    	if(i >= 12){
    		dp[i] = min(dp[i], dp[i - 12] + l);
    	}
    }

    int mn = 1e9;
    for(int i = n; i <= 144; i++){
        mn = min(mn, dp[i]);
    }

    cout << mn << "\n";

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