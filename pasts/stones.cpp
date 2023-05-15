
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
    int k;
    cin >> k;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<vector<int>> dp(k + 1, vector<int>(2, 0));
    dp[0][0] = 1;
    dp[0][1] = 1;
    for(int i = 0; i < n; i++){
    	dp[ele[i]][0] = 1;
    	dp[ele[i]][1] = 1;
    }
    for(int i = 0; i <= k; i++){
    	for(int j = 0; j <= 1; j++){
    		int val = 1;
    		for(int l = 0; l < n && ele[l] <= i; l++){
    			val = (val & dp[i - ele[l]][(j + 1) % 2]);
    		}
    		dp[i][j] = (!val);
    	}
    }
    if(dp[k][0]){
    	cout << "First" << "\n";
    }
    else{
    	cout << "Second" << "\n";
    }
    //there are two things that matter whose move is it and what value do we have here
    //dp[i] // the sum that we have and j is the move of then participant
    //dp[i][j] = V(k in n) dp[i - a[k]][j - 1]// if in any case I win i would do that move right?
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