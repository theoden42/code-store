
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i] >> b[i];
    }

    vector<int> c(n);
    for(int i = 0; i < n; i++){
    	c[i] = a[i] * b[i];
    }

    int count = 1;
    int gd = c[0];
    int lm = b[0];

    for(int i = 1; i < n; i++){

    	gd = gcd(gd, c[i]);
    	lm = (lm * b[i]) / gcd(lm, b[i]);

    	if(gd % lm == 0){
    		continue;
    	}
    	else{
    		count++;
    		lm = b[i];
    		gd = c[i];
    	}

    }

    cout << count << "\n";


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}