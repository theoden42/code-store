#include<bits/stdc++.h> 
using namespace std;
 
//---------------xx-----------------xx----------------------xx--------------------------xx-------------------------xx----------------------------xx---------------------------------xx//
 
void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    sort(v.begin(), v.end());
 
    int m=1e9+7;
     
   
    for (int i = x; i >= 0; i--)
    {
        dp[n - 1][i] = 0;
    }
    for (int j = n - 1; j >= 0; j--)
    {
        dp[j][x] = 1;
    }
     
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = x - 1; j >= 0; j--)
        {
 
            if (j + v[i] > x)
            {
                dp[i][j] = dp[i + 1][j];
                dp[i][j] %= m;
            }
            else
            {
                dp[i][j] = dp[i][j + v[i]] + dp[i + 1][j ];
                dp[i][j] %= m;
            }
        }
    }
 
     cout << dp[0][0];
}
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    solve();

    return 0;
}