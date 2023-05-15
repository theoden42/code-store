
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
    int a, b;
    cin >> a >> b;
    long double val = 1.0 * a * b;
    long double l = 0;
    long double u = 4.0 * max(a, b);

    long double len = -1.0;
    const long double root3 = 1.73205080757;

    for(int i = 0; i < 100; i++){
    	double mid = l + (u - l) / 2;
    	double area = (root3 * mid * mid) / 4.0000;
    	debug(mid, area);
    	if(area <= val){
    		len = mid;
    		l = mid;
    	}
    	else{
    		u = mid;
    	}
    }
    cout << setprecision(12) << len << "\n";
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