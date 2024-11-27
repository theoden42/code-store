
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
    ll n, m;
    cin >> n >> m;
    ll val = n / m;
    ll min = 1ll * (m - n % m) * (val * (val - 1)) / 2;
    val = val + 1;
    min += 1ll * (n % m) * (val * (val - 1)) / 2;
    ll max = 0;
    max = (n - m + 1) * (n - m) / 2;
    cout << min << " " << max << "\n";

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