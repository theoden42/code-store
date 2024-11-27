
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(n % 2 == 0 && k == n / 2){
    	cout << "NO" << "\n";
    	return;
    }
    for(int i = 0; i < k; i++){
    	if(s[i] != s[n - 1 - i]){
    		cout << "NO" << "\n";
    		return;
    	}
    }
    cout << "YES" << "\n";
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