
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
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
    sort(all(ele));
    vector<vector<int>> dp(n, vector<int>(1e5 + 5, -1));
    dp[0][0] = 1;
   	dp[0][ele[0]] = 1;
    for(int i = 1; i < n; i++){
    	for(int j = 0; j <= 1e5; j++){
    		if(dp[i - 1][j] != -1 ){
    			dp[i][j] = 1;
    			if(j + ele[i] <= 1e5){
    				dp[i][j + ele[i]] = 1;
    			}
    		}
    	}	
    }
    vector<int> ans;
    for(int j = 1; j <= 1e5; j++){
    	if(dp[n - 1][j] != -1){
    		ans.push_back(j);
    	}
    }
    cout << ans.size() << "\n";
    for(auto& x: ans){
    	cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}