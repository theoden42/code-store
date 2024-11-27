

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
    vector<int> p(n);
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }

    vector<double> pow(n), powsum(n);
    pow[0] = 1;
    for(int i = 1; i < n; i++){
    	pow[i] = pow[i - 1] * (0.9D);
    }
    powsum[0] = pow[0];
    for(int i = 1; i < n; i++){
    	powsum[i] = powsum[i - 1] + pow[i];
    }

    vector<vector<double>> dp(n, vector<double>(n + 1, -1e18));
    dp[0][1] = p[0] - 1200;
    for(int i = 1; i < n; i++){
    	dp[i][1] = max(dp[i - 1][1], (double)p[i] - 1200);
    }

    for(int i = 1; i < n; i++){
    	for(int j = 2; j <= n; j++){
    		dp[i][j] = max(dp[i - 1][j], dp[i][j]);
            if(dp[i - 1][j - 1] == -1e18)
                continue;
    		double prev = dp[i - 1][j - 1];
    		double sum = prev + (1200 / sqrtl(j - 1));
            sum *= powsum[j - 2];
    		sum *= 0.9;
    		double newsum = sum + p[i];
    		newsum /= powsum[j - 1];
    		newsum -= (1200 / sqrtl(j));
    		dp[i][j] = max(dp[i][j], newsum);	
    	}
    }

    double mx = -1e18;
    for(int j = 1; j <= n; j++){
    	mx = max(mx, dp[n - 1][j]);
    }

    cout << fixed << setprecision(15) << mx << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   //q cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}