
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

ll ele[5000];
ll dp[5000][5000][2];


ll findans(int i, int j, int mv){
	if(dp[i][j][mv] != -1){
		return dp[i][j][mv];
	}
	if(i == j){
		if(mv == 0)
			dp[i][j][mv] = ele[i];
		else
			dp[i][j][mv] = 0;
	}
	else if(mv == 0){
		dp[i][j][mv] =  max(ele[i] + findans(i + 1, j, 1), ele[j] + findans(i, j - 1, 1));
	}
	else{
		dp[i][j][mv] = min(findans(i + 1, j, 0), findans(i, j - 1, 0));
	}
	return dp[i][j][mv];
}

void solve() {
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    for(int i = 0; i < 5000; i++){
    	for(int j = 0; j < 5000; j++){
    		for(int k = 0; k < 2; k++){
    			dp[i][j][k] = -1;
    		}
    	}
    }
    ll ans = 0;
    ans = findans(0, n - 1, 0);
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