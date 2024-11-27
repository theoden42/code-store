
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
    ll n;
    cin >> n;
    vector<ll> t(n + 1);
    vector<ll> x(n + 1);
    vector<ll> a(n + 1);
    t[0] = 0;
    x[0] = 0;
    a[0] = 0;
    for(int i = 1; i <= n; i++){
    	cin >> t[i] >> x[i] >> a[i];
    }

    vector<vector<ll>> dp(n + 1, vector<ll>(2, 0));
    dp[1][0] = 0;
    if(t[1] >= x[1]){
    	dp[1][1] = a[1];
    }
    else{
    	dp[1][1] = -1;
    }

    for(int i = 1; i <= n; i++){
    	for(int j = i - 1; j >= 0 && j >= i - 5; j--){
    		if(dp[j][1] != -1){
    			dp[i][0] = max(dp[i][0], dp[j][1]);
    			if(t[i] - t[j] >= abs(x[i] - x[j])){
    				dp[i][1] = max(dp[i][1], dp[j][1] + a[i]);
    			}
    		}
    	}
    	if(dp[i][1] == 0){
    		dp[i][1] = -1;
    	}
    }
    for(int i = 0; i <= n; i++){
    	cout << dp[i][0] << " " << dp[i][1] << "\n";
    }
    ll mx = 0;
    for(int i = 0; i <= n; i++){
    	mx = max({dp[i][1], dp[i][0], mx});
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