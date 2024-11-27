
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

void solve() {
    int l;
    cin >> l;
    vector<int> dp(l + 1, 1e9);
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= l; i++){
    	dp[i] = min(dp[i], dp[i - 1] + 1);
    	for(int j = 2; j * j <= i; j++){
    		if(i % j == 0){
    			dp[i] = min(dp[i], dp[j] + 4 + 2 * (i / j - 1));
    			dp[i] = min(dp[i], dp[i / j] + 4 + 2 * (j - 1)); 
    		}
    	}
    }
    cout << dp[l] << "\n";
    debug(dp); 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        	 cout << "Case #" << t << ": ";
        solve();
    }
}