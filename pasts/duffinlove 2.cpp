
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int check(int n){
	for(int i = 2; i * i <= n; ++i){
		int count = 0;
		while(n % i == 0){
			count++;
			n /= i;
		}
		if(count > 1){
			return false;
		}
	}
	return true;
}

void solve() {
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 1; i * i <= n; i++){
    	if(n % i != 0)continue;
    	int a = i;
    	int b = n / i;
    	if(check(a)){
    		mx = max(mx, a);
    	}
    	if(check(b)){
    		mx = max(mx, b);
    	}
    }
    cout << mx << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}