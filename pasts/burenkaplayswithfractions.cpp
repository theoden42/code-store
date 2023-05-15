
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
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a == 0 || c == 0){
    	if(a == 0 && c == 0){
    		cout << 0 << "\n";
    	}
    	else{
    		cout << 1 << "\n";
    	}
    	return;
    }
    ll e = a * d;
    ll f = b * c;
    if(e == f){
    	cout << 0 << "\n";
    }
    else if(max(e, f) % min(e, f) == 0){
    	cout << 1 << "\n";
    }
    else{
    	cout << 2 << "\n";
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