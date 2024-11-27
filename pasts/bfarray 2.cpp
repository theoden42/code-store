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
    ll n, k, b, s;
    cin >> n >> k >> b >> s;
    vector<ll> ans(n, 0);

    if(n == 1){
    	if(b == s/k){
    		cout << s << "\n";
    	}
    	else{
    		cout << "-1" << "\n";
    	}
    	return;
    }
	if(s < b * k || ceil((s - k * (b + 1) + 1) / (n - 1)) >= k){
		cout << "-1" << "\n";
	}
	else{
		ll sum = s;
		ans[0] = min(s, k * (b + 1) - 1);
		sum -= ans[0];
		for(int i = n - 1 ; i > 0; i--){
			ans[i] = sum / (n - 1);
		}

		int count = sum - (n - 1) * (sum / (n - 1));
		for(int i = n - 1; i > 0; i --){
			if(count > 0){
				ans[i]++;
				count--;
			}
		}
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
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