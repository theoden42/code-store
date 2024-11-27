

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

vector<int> pw(17);
void preproces(){
	pw[0] = 1;
	for(int i = 1; i < 17; i++){
		pw[i] = pw[i - 1] * 10;
	}
}

int index(int n, int i){
	vector<int> val(15);
	for(int i = 0; i < 15; i++){
		val[i] = n % 10;
		n /= 10;
	}
	return val;
}

int dfs(int ind, int sum, int rem, int tight, int n, int mxsum, vector<int> index, vector<vector<vector<vector<int>>>>& dp){
	if(dp[ind][sum][rem][tight] != -1)
		return dp[ind][sum][rem][tight];

	if(ind == 15){
		if(rem == 0 && sum == mxsum){
			return 1;
		}
	}
	if(tight){
		for(int i = 0; i < index[ind]; i++){
			dp[ind][sum][rem][tight] += dfs(ind + 1, sum + i, (sum + i * pw[ind]))
		}
	} else {
		for(int i = 0; i <= 9; i++){
			dp[ind][sum][rem][0] += dfs(ind + 1, sum + i, (sum + i * pw[15 - ind]) % mxsum, n, mxsum, index, dp);
		}
	}

	int ind = 0;
}

int calc(int n, int sum){
	vector dp(16, vector(sum + 1, vector(sum, vector<int>(2, -1))));
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < sum; j++){
			for(int k = 0; k < sum; k++){
				dp[i][j][k][0] = dp[i][j][k][1] = -1;
			}
		}
	}

	vector<int> temp = index(n);
	dfs(0, 0, 0, 1, n, temp, dp);

	int ans = dp[15][sum][0][0] + dp[15][sum][0][1];

	return ans;
}


void solve() {
    int n;
    cin >> n;
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