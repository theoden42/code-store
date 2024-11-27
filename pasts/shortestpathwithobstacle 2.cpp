
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
    int xa, ya, xb, yb, xf, yf;
    cin >> xa >> ya >> xb >> yb >> xf >> yf;
    if(xa == xb || ya == yb){
    	if(xa == xb){
    		if(xf == xa && yf < max(ya, yb) && yf > min(ya, yb)){
    			cout << abs(yb - ya) + 2 << "\n";
    		}
    		else{
    			cout << abs(yb - ya) << "\n";
    		}
    	}
    	else{
    		if(yf == ya && xf < max(xa, xb) && xf > min(xa, xb)){
    			cout << abs(xb - xa) + 2 << "\n";
    		}
    		else{
    			cout << abs(xb - xa) << "\n";
    		}
    	}
    }
    else{
    	cout << abs(yb - ya) + abs(xb - xa) << "\n";
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