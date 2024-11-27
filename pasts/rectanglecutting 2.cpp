
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

const int MAX_N = 1e9 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<vector<ll>> dp(505, vector<ll>(505, MAX_N));

ll nmvs(int a, int b){

	if(dp[a][b] != MAX_N){
	}
	else if(a == 1 || b == 1){
		dp[a][b] = (ll)max(a, b) - 1;
	}
	else if(a == b){
		dp[a][b] = 0;
	}
	else{
		ll mn = 1e5;
		for(int i = 1; i < b; i++){
			mn = min(mn, nmvs(a, i) + nmvs(a, b - i) + 1);
		}
		for(int i = 1; i < a; i++){
			mn = min(mn, nmvs(i, b) + nmvs(a - i, b) + 1);
		}
		dp[a][b] = mn;
	}
	return dp[a][b];
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << nmvs(a, b) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //	cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}