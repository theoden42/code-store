
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
   int n, m;
   cin >> n >> m;
   vector<int> ele(n, 0);
   for(int i = 0; i < n; i++){
   	cin >> ele[i];
   	ele[i] = ele[i] % m;
   }

   if(n > m){

   	cout << "YES\n";
   	return;
   }

   vector<vector<int>> dp(n, vector<int>(m, 0));
   dp[0][ele[0]] = 1;

   for(int i = 1; i < n; i++){
   	dp[i][ele[i] % m] = 1;
   	for(int j = 0; j < m; j++){
   		if(dp[i - 1][j]){
   			dp[i][(j + ele[i]) % m] = 1;
   			dp[i][j] = 1;
   		}
   	}
   }

   debug(dp);
   if(dp[n - 1][0]){
   		cout << "YES\n";
   }
   else{
   		cout << "NO\n";
   }

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