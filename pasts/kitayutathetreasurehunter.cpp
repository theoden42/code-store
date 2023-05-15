
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

const int MAX_N = 300;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



void solve() {
   int n, d;
   cin >> n >> d;
   vector<int> gems(MAX_N);
   for(int i = 0; i < MAX_N; i++){
   	cin >> gems[i];
   }

   vector<ll> dp(MAX_N);

   ll mx = 0;
   for(int i = d + 1; i < MAX_N; i++){
   		for(int j = 0; j < MAX_N; j++){
   			dp[j] = 0; 
   		}
   		dp[d] = gems[d];
   		for(int j = 1; j < MAX_N; j++){
   			if(i - j >= 0)
   				dp[i] = max(dp[i], dp[i - j]);
   			if(i - j - 1 >= 0)
   				dp[i]= max(dp[i], dp[i - j - 1]);
   			if(i - j + 1 >= 0)
   				dp[i] = max(dp[i], dp[i - j + 1]);
   			dp[i] += gems[i];
   			mx = max(dp[i], mx);
   		}
   }
   cout << mx << "\n";



  
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