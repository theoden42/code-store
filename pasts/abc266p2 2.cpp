
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const ll MOD =  998244353;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    ll n; 
    cin >> n;
    ll ans = 0;
    if(n < 0){
    	n = -1 * n;
    	if(n % MOD != 0)
    	ans = MOD - n % MOD;
    }
    else{
    	ans = n % MOD;
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