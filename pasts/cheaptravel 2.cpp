
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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if(b > m * a){
    	cout << n * a << "\n";
    }
    else{
    	if(n % m == 0){
    		cout << b * (n / m) << "\n";
    	}
    	else{
    		cout << min(b * (n / m) + b, b * (n / m) + a * (n - (n / m) * m)) << "\n";
    	}
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