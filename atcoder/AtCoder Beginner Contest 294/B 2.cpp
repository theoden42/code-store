
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
    int h, w;
    cin >> h >> w;
    for(int i = 0; i < h; i++){
    	string x = "";
    	for(int j = 0; j < w; j++){
    		int t;
    		cin >> t;
    		if(t == 0){
    			x += '.';
    		}
    		else{
    			x += ('A' + (t - 1));
    		}
    	}
    	cout << x << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}