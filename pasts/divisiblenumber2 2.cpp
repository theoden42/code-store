
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(c >= 2 * a && d >= 2 * b){
    	cout << 2 * a << " " << 2 * b << "\n";
    	return;
    }
    else if(2 * a > b && 2 * a <= d && b > a && b <= c){
    	cout << b << " " << 2 * a << "\n";
    	return;
    }
    else if(2 * b > a && 2 * b <= c && a > b && a <= d){
    	cout << 2 * b << " " << a << "\n";
    	return;
    }
   	else if(a % 2 == 0){
   		ll x1 = 3 * a / 2;
   		ll x2 = 2 * b;
   		if(x1 > a && x1 <= c && x2 > b && x2 <= d){
   			cout << x1 << " " << x2 << "\n";
   			return;
   		}
   		else if(x1 > b && x1 <= d && x2 > a && x2 <= c){
   			cout << x2 << " " << x1 << "\n";
   			return;
   		}
   	}
   	else if(b % 2 == 0){
   		ll x1 = 3 * b / 2;
   		ll x2 = 2 * a;
   		if(x1 > a && x1 <= c && x2 > b && x2 <= d){
   			cout << x1 << " " << x2 << "\n";
   			return;
   		}
   		else if(x1 > b && x1 <= d && x2 > a && x2 <= c){
   			cout << x2 << " " << x1 << "\n";
   			return;
   		}
   	}
   	cout << "-1 -1\n";


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