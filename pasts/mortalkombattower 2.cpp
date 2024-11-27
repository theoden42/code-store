 
 /* @uthor: (g)theoden42 */
 
 #include <bits/stdc++.h>
 using namespace std;
 
 #define ll long long
 #define ld long double
 #define all(a) (a).begin(), (a).end()
 
 const int MAX_N = 2e5 + 5;
 const ll MOD = 1e9 + 7;
 const ll INF = 1e9;
 const ld EPS = 1e-9;
 
 void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
        cin >> ele[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    dp[n - 1][0] = (ele[n - 1] == 1) ? 1 : 0;
    dp[n - 1][1] = 0; 
    for(int i = n - 2; i >= 0; i--){
        dp[i][1] = min(dp[i + 1][0], dp[i + 2][0]);
        if(ele[i] == 1 && ele[i + 1] == 1){
            dp[i][0] = min(dp[i + 1][1] + 1, dp[i + 2][1] + 2);
        } 
        else if(ele[i] == 0 && ele[i + 1] == 1){
            dp[i][0] = min(dp[i + 1][1], dp[i + 2][1] + 1);
        } 
        else if(ele[i] == 1 && ele[i + 1] == 0){
            dp[i][0] = min(dp[i + 1][1] + 1, dp[i + 2][1] + 1);
        } 
        else{
            dp[i][0] = min(dp[i + 1][1], dp[i + 2][1]);
        } 
    }
    // for(auto& x: dp){
    //     cout << x[0] << " " << x[1] << "\n";
    // }
    cout << dp[0][0] << "\n";
 }
 
 int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     int tc = 1;
     cin >> tc;
     for (int t = 1; t <= tc; t++) {
         // cout << "Case #" << t << ": ";
         solve();
     }
 }