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

map<int,int> distinct;


int getgem(int ind, int ljump, vector<int>& gems, vector<vector<int>>& dp, int d){
	int x = ljump - d + 250;

	if(ind > 30000){
		return 0;
	}

	if(dp[ind][x] != -1){
		return dp[ind][x];
	}

	dp[ind][x] = gems[ind];
	int val = 0;

	if(ljump != 1){
		val = max(val, getgem(ind + ljump - 1, ljump - 1, gems, dp, d));
	}
	val = max(val, getgem(ind + ljump, ljump, gems, dp, d));
	val = max(val, getgem(ind + ljump + 1, ljump + 1, gems, dp, d));

	dp[ind][x] += val;
	return dp[ind][x];

}


void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> gems(30001, 0);
    for(int i = 0; i < n; i++){
    	int p;
    	cin >> p;
    	gems[p]++;
    }

    vector<vector<int>> dp(30001, vector<int>(800, -1));

    cout << getgem(d, d, gems, dp, d) << "\n";

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