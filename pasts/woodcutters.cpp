
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()
#define int long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9 ;
const ld EPS = 1e-9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	int x, h;
    	cin >> x >> h;
    	vp[i] = {x, h};
    }
    vector<int> diff(n + 1);
    for(int i = 1; i < n; i++){
        diff[i] = vp[i].first - vp[i - 1].first;
    }

    vector<vector<int>> dp(n , vector<int> (3, 0));
    diff[0] = INF;
    diff[n] = INF;
    // for(auto& x: diff){
    //     cout << x << " ";
    // }
    // cout << "\n";
    dp[0][0] = 0;
    dp[0][1] = 1;
    if(diff[1] > vp[0].second){
        dp[0][2] = 1;
    }
    else{
        dp[0][2] = 0;
    }

    for(int i = 1; i <= n - 1; i++){
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        if(vp[i - 1].second + vp[i].second < diff[i]){
            dp[i][1] = dp[i - 1][2] + 1;
        }
        else if(vp[i].second < diff[i]){
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        else{
            dp[i][1] = dp[i][0];
        }
        if(vp[i].second < diff[i + 1]){
            dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        }
        else{
            dp[i][2] = dp[i][0];
        }
    }
    // for(auto&x: dp){
    //     cout << x[0] << " " << x[1] << " " << x[2] << "\n";
    // }
    cout << max({dp[n - 1][0] + 1, dp[n - 1][2], dp[n - 1][1]}) << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}