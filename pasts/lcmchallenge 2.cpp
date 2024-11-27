
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
    int a = n;
    int b = n - 1;
    if(n <= 2){
    	cout << n << "\n";
    	return;
    }
    int c = 0;
    if(n % 2 == 1){
    	c = n - 2;
    }
    else
    for(int i = 3; i <= (n/2 + 1); i += 2){
    	if(n % i != 0){
    		c = n - i;
    		break;
    	}
    }
    ll ans = 0;
    if(c == 0){
    	 ans = max(1ll * a * b * (n - 2) / 2, 1ll * (a - 1) * (b - 1) * (n - 3));
    }
    else{
    	 ans = max(1ll * a * b * c, 1ll * (a - 1) * (b - 1) * (n - 3));
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