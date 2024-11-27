
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[5005][5005][2];

int f(int ind, int lstpgm, int lstcpu, vector<int>& ele, vector<int>& hot, vector<int>& cold){
	int n = ele.size();

	if(ind == n)return 0;
	int jb = ele[ind];

	if(dp[ind][lstpgm][lstcpu] != -1)return dp[ind][lstpgm][lstcpu];


	if(ind > 1 && jb == ele[ind - 1]){
		return dp[ind][lstpgm][lstcpu] = hot[ele[ind]] + f(ind + 1, lstpgm, lstcpu, ele, hot, cold);
	}
	else if(ind > 1 && jb == lstpgm){
		int temp = ele[ind - 1];
		return dp[ind][lstpgm][lstcpu] = hot[ele[ind]] + f(ind + 1, temp, (lstcpu ^ 1), ele, hot, cold); 
	}
	else{
		int ans = cold[ele[ind]] + f(ind + 1, lstpgm, lstcpu, ele, hot, cold);
		ans = min(ans, cold[ele[ind]] + f(ind + 1, ele[ind - 1], (lstcpu ^ 1), ele, hot, cold));
		return dp[ind][lstpgm][lstcpu] = ans;
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ele(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> ele[i];
    }
    vector<int> cold(k + 1);
    for(int i = 1; i <= k; i++){
    	cin >> cold[i];
    }
    vector<int> hot(k + 1);
    for(int i = 1; i <= k; i++){
    	cin >> hot[i];
    }

    for(int i = 0; i <= n; i++){
    	for(int j = 0; j <= k; j++){
    		for(int k = 0; k < 2; k++){
    			dp[i][j][k] = -1;
    		}
    	}
    }


    int ans = 0;
    ans = cold[ele[1]] + f(2, ele[1], 0, ele, hot, cold);

    cout << ans << "\n";

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