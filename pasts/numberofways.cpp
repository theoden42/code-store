
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
    vector<ll> prefix(n, 0);
    prefix[0] = ele[0];
    for(int i = 1; i < n; i++){
    	prefix[i] = prefix[i - 1] + ele[i];
    }
    // for(int i = 0; i < n; i++){
    // 	cout << prefix[i] << " ";
    // }
    // cout << "\n";
    ll sum = prefix[n - 1];
    if(sum % 3 != 0){
    	cout << "0" << "\n";
    	return;
    }
    int count = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++){
    	if(prefix[i] == 2 * sum / 3 && i != n - 1){
    		ans += count;
    	}
    	if(prefix[i] == sum / 3){
    		count++;
    	}
    }
    cout << ans << "\n";
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