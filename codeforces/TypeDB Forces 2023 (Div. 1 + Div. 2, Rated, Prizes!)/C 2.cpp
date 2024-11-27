
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define int long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int f(int index, int smaller, int s, vector<int>& ele, vector<vector<int>>& dp){
    
    int xp, yp, xn, yn;
    int n = ele.size() - 1;
    if(index == 2){
        xp = 0;
        yp = ele[1];
    }
    else{
        if(!smaller && ele[index - 1] <= s){
            xp = ele[index - 1];
            yp = 0;
        }
        else if(smaller && ele[index - 1] > s){
            xp = min(ele[index - 1] - s, s);
            yp = max(ele[index - 1] - s, s);
        }
        else if(smaller && ele[index - 1] <= s){
            xp = 0;
            yp = ele[index - 1];
        }
        else{
            xp = max(ele[index - 1] - s, s);
            yp = min(ele[index - 1] - s, s);
        }
    }

    if(index == n){
        // debug(yp * ele[n]);
        return yp * ele[n];
    }

    if(ele[index] <= s){
        xn = ele[index];
        yn = 0;
    }
    else{
        xn = max(ele[index] - s, s);
        yn = min(ele[index] - s, s);
    }

    if(dp[index][smaller] != -1)return dp[index][smaller];


    dp[index][smaller] = xn * yp + f(index + 1, 0, s, ele, dp);

    if(ele[index] <= s){
        xn = 0;
        yn = ele[index];
    }
    else{
        xn = min(ele[index] - s, s);
        yn = max(ele[index] - s, s);
    }

    dp[index][smaller] = min(dp[index][smaller], xn * yp + f(index + 1, 1, s, ele, dp));
    return dp[index][smaller];

}

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> ele(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> ele[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

     cout << f(2, 0, s, ele, dp) << "\n";

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