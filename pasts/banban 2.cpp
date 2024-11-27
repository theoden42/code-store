
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
    	int ans = n / 2;
    	cout << ans << "\n";
    	int counta = 2;
    	int countb = 3 * n;
    	for(int i = 1; i <= n / 2; i++){
    		cout << counta << " " << countb << "\n";
    		counta += 3;
    		countb -= 3;
    	}
    }
    else{
		int ans = (n + 1)/2;
		cout << ans << "\n";
		int counta = 2;
    	int countb = 3 * n;
    	for(int i = 1; i <= n / 2; i++){
    		cout << counta << " " << countb << "\n";
    		counta += 3;
    		countb -= 3;
    	}
    	cout << 3 * (n / 2) + 2 << " " << 3 * (n / 2) + 3 << "\n";
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