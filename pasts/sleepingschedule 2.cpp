
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int f(int ind, int wtime, vector<int>& ele, vector<vector<int>>& dp, int l, int r, int h){
	if(ind == ele.size()){
		return 0;
	}
	if(dp[ind][wtime] != -1){
		return dp[ind][wtime];
	}
	int newtime1 = (wtime + ele[ind]) % h;
	int newtime2 = (wtime + ele[ind] - 1) % h;
	if(newtime1 >= l && newtime1 <= r){
		dp[ind][wtime] = max(dp[ind][wtime], 1 + f(ind + 1 , newtime1, ele, dp, l, r, h));
	}
	else{
		dp[ind][wtime] = max(dp[ind][wtime], f(ind + 1, newtime1, ele, dp, l, r, h));
	}

	if(newtime2 >= l && newtime2 <= r){
		dp[ind][wtime] = max(dp[ind][wtime], 1 + f(ind + 1 , newtime2, ele, dp, l, r, h));
	}
	else{
		dp[ind][wtime] = max(dp[ind][wtime], f(ind + 1, newtime2, ele, dp, l, r, h));
	}

	return dp[ind][wtime];

}

void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(h, -1));
    cout << f(0, 0, a, dp, l, r, h) << "\n";	
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