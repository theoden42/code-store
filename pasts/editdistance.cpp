
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

string s, t;


int editdistance(vector<vector<int>>& dp, int i, int j){
    if(i == -1 && j == -1){
        return 0;
    }
    else if(i == -1){
        return j + 1;
    }
    else if(j == -1){
       return i + 1;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    else{
        if(s[i] == t[j]){
            dp[i][j] = editdistance(dp, i - 1, j - 1);
        }
        else{
            dp[i][j] = editdistance(dp, i - 1, j - 1) + 1;
        }
        dp[i][j] = min(dp[i][j], editdistance(dp, i, j - 1) + 1);
        dp[i][j] = min(dp[i][j], editdistance(dp, i - 1, j) + 1);
    }
    return dp[i][j];
}

void solve() {
    cin >> s;
    cin >> t;
    int n = s.size();
    int m = t.size();
    int ans = 0;
    vector<vector<int>> dp(5000, vector<int>(5000, -1));
    ans = editdistance(dp, n - 1, m - 1);
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