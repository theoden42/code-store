
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
    int n;
    cin >> n;

    ll c = 0;
    ll c2 = 0;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j * j <= i; j++){
    		if(i % j == 0){
    			c++;
    			c2 += j;
    			if(i / j != j){
    				c++;
    				c2 += i / j;
    			}
    		}
    	}
    }	
    cout << c << " " << c2 << "\n";
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