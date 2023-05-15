
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

int nof(int x){
	int count = 0;
	for(int i = 1; i * i <= x; i++){
		if(x % i == 0){
			if(x / i == i)count++;
			else count += 2;
		}
	}
	return count;
}

void solve() {
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i <= n; i++){
    	int a = i;
    	int b = n - a;
        ll value = nof(a);
        value = value * nof(b);
        ans += value;
    }
    cout << ans << "\n";
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