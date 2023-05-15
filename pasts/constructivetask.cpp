
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
    if(n == 3){
    	cout << "NO\n";
    	return;
    }
    if(n & 1){
    	cout << "YES\n";
    	for(int i = 1; i <= n; i++){
    		if(i % 2 == 1){
    			cout << n - 3 << " ";
    		}
    		else{
    			cout << -1 * (n - 1) << " ";
    		}
    	}
    	cout << "\n";
    }
    else{
    	cout << "YES\n";
    	for(int i = 1; i <= n / 2; i++){
    		cout << "1 -1 ";
    	}
    	cout << "\n";
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