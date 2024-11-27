
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
    vector<ll> ele(n, 0);
    ll sum = 0;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	sum += ele[i];
    }
    sort(all(ele));
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
    	ll x, y;
    	cin >> x >> y;
    	ll ma = 2e18;
    	int l = 0;
    	int u = n - 1;
    	while(l <= u){
    		int mid = l + (u - l)/2;
    		if(ele[mid] >= x){
    			ll coins = max(0ll, x - ele[mid]) + max(0ll, y - sum + ele[mid]);
    			ma = min(coins, ma);
    			u = mid - 1;

    		}
    		else{
    			ll coins = max(0ll, x - ele[mid]) + max(0ll, y - sum + ele[mid]);
    			ma = min(coins, ma);
    			l = mid + 1;
    		}
    	}
    	cout << ma << "\n";
    }

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