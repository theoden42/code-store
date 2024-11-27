
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
    ll n, k;
    cin >> n >> k;
    vector<ll> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    if(k > n){
    	ll ans = k - n;
    	for(int i = 0; i < n; i++){
    		ans += ele[i];
    	}
    	ans += (k - n) * (n - 1);
    	ans += (n * (n - 1)) / 2;
    	cout << ans << "\n";
    }
    else{
    	vector<ll> prefix(n, 0);
    	for(int i = 0; i < n; i++){
    		if(i != 0){
    			prefix[i] = ele[i] + prefix[i - 1];
    		}
    		else{
    			prefix[i] = ele[i];
    		}
    	}
    	ll m = 0;
    	for(int i = 0; i <= n - k; i++){
    		ll sum = prefix[i + k - 1] - prefix[i] + ele[i];
    		m = max(m, sum);
    	}
    	ll ans = m + k * (k - 1) / 2;
    	cout << ans << "\n";
    }
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