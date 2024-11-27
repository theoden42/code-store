
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
    if(n % 2 == 0){
    	cout << n / 2 << " " << n / 2 << "\n";
    	return;
    }

    int mn = n;

    for(int i = 2; i * i <= n; i++){
    	if(n % i == 0){
    		int a = i;
    		int b = n - i;
    		mn = min(max(a, b), mn);


    		a = n / i;
    		b = n - a;
    		mn = min(max(a, b), mn);
    	}
    }

    if(mn == n){
    	cout << 1 << " " << n - 1 << "\n";
    }
    else{
    	cout << mn << " " << n - mn << "\n";
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