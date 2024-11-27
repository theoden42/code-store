
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
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    int c1 = 0, c2 = 0;
    int c3 = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] == 1){
    		c1++;
    	}
    	if(b[i] == 1){
    		c2++;
    	}
    	if(a[i] != b[i]){
    		c3++;
    	}
    }
    cout << min(c3, abs(c1 - c2) + 1) << "\n";

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