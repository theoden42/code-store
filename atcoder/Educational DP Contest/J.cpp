

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

double f(int i, int j, int k, int n, vector<vector<vector<double>>>& dp){

	// debug(i, j, k, dp[i][j][k]);

	if(i == 0 && j == 0 && k == 0){
		return 0;
	}

	if(dp[i][j][k] != -1)return dp[i][j][k];

	dp[i][j][k] = 0;

	if(i != 0){
		dp[i][j][k] += (1.0 * i / n) * (1 + f(i - 1, j, k, n, dp));
	}
	if(j != 0){
		dp[i][j][k] += (1.0 * j / n) * (1 + f(i + 1, j - 1, k, n, dp));
	}
	if(k != 0){
		dp[i][j][k] += (1.0 * k / n) * (1 + f(i, j + 1, k - 1, n, dp));
	}

	if(i + j + k < n && i + j + k > 0){
		// debug("before", dp[i][j][k]);
		dp[i][j][k] *= (1.0 * n / (i + j + k));
		dp[i][j][k] += (1.0 * n) / (i + j + k) - 1;
		// debug("after", dp[i][j][k]);
	}

	return dp[i][j][k];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }


    int a1 = 0;
    int b = 0;
    int c = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == 1){
    		a1++;
    	}else if(a[i] == 2){
    		b++;
    	}else{
    		c++;
    	}
    }


    vector<vector<vector<double>>> dp(n + 1, vector<vector<double>>(n + 1, vector<double>(n + 1, -1)));
    dp[0][0][0] = 0;

    // debug(a1, b, c);

    cout << setprecision(10) << f(a1, b, c, n, dp) << "\n";

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