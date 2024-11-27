
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

ll maxheight(int index, int pos, vector<int>& h1, vector<int>& h2, vector<vector<ll>>& dp){
	if(dp[index][pos] != -1){
		return dp[index][pos];
	}
	if(index == 0){
		if(pos == 0){
			dp[index][pos] = h1[0];
			return h1[0];
		}
		else{
			dp[index][pos] = h2[0];
			return h2[0];
		}
	}
	if(pos == 0){
		dp[index][pos] = max(maxheight(index - 1, 1, h1, h2, dp) + h1[index], maxheight(index - 1, pos, h1, h2, dp));
	}
	else{
		dp[index][pos] = max(maxheight(index - 1, 0, h1, h2, dp) + h2[index], maxheight(index - 1, pos, h1, h2, dp));
	}
	return dp[index][pos];
}

void solve() {
    int n;
    cin >> n;
    vector<int> h1(n, 0);
    vector<int> h2(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> h1[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> h2[i];
    }
    vector<vector<ll>> dp(n, vector<ll>(2, -1));
    ll ans = max(maxheight(n - 1, 0, h1, h2, dp), maxheight(n - 1, 1, h1, h2, dp));
    cout << ans << "\n";
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