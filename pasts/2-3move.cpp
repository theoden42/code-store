
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
    if(n == 1){
        cout << 2 << "\n";
        return;
    }
    int l = n % 3;
    if(l == 0){
    	cout << n / 3 << "\n";
    }
    else if(l == 2){
    	cout << (n - 2) / 3 + 1 << "\n";
    }
    else{
    	ll ans = (n - 4)/3 + 2;
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