
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
    map<int, int> mp;
    int m = -1;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	mp[ele[i]]++;
    	m = max(m, ele[i]);
    }
    vector<ll> fi(m + 1, 0);
    sort(all(ele));
    for(int i = 0; i < n; i++){
    	if(mp[ele[i]] != 0){
    		fi[ele[i]] = 1ll * ele[i] * mp[ele[i]];
    		mp[ele[i]] = 0;
    	}
    }
    // for(auto& x: fi){
    // 	cout << x << " ";
    // }
    // cout << "\n";
    vector<ll> dp(m + 1, 0);
    for(int i = 1; i < m + 1; i++){
    	if(i - 2 >= 0){
    		dp[i] = max(dp[i - 1], fi[i] + dp[i - 2]);
    	}
    	else{
    		dp[i] = max(dp[i - 1], fi[i]);
    	}
    }
    ll mn = 0;

    for(auto& x: dp){
    	// cout << x << " ";
    	mn = max(mn, x);
    }
    // cout << "\n";
    cout << mn << "\n";

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