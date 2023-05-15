
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


int f(int i, int j, string& s, string& m, int l,  vector<vector<int>>& dp){
	int ind = i + (l - 1 - j);

	if(i == j){
		if(s[ind] == m[i]){
			return dp[i][j] = 1;
		}
		else{
			return dp[i][j] = 0;
		}
	}

	if(dp[i][j] != -1)return dp[i][j];

	dp[i][j] = 0;
	if(m[j] == s[ind]){
		dp[i][j] |= f(i, j - 1, s, m, l, dp);
	}
	if(m[i] == s[ind]){
		dp[i][j] |= f(i + 1, j, s, m, l, dp);
	}

	return dp[i][j];
}


void solve() {
    int l;
    cin >> l;
    string s, m;
    cin >> s >> m;

    int i = 0;
    int j = l - 1;
    vector<vector<int>> dp(l, vector<int>(l, -1));

    if(f(i, j, s, m, l, dp)){
    	cout << "YES\n";
    }
    else{
    	cout << "NO\n";
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
         cout << "Case " << t << ": ";
        solve();
    }
}