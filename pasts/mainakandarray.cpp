
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){	
    	cin >> ele[i];
    }
    int m1 = ele[n - 1] - ele[0];
    for(int i = n - 1; i >= 1; i--){
    	m1 = max(ele[i - 1] - ele[i], m1);
    }
	int m2 = 0;
	for(int i = 1; i < n; i++){
		m2 = max(ele[i], m2);
	}
	m2 = m2 - ele[0];
	int m3 = 1e9;
	for(int i = 0; i < n - 1; i++){
		m3 = min(m3, ele[i]);
	}
	m3 = ele[n - 1] - m3;
	cout << max({m1, m2, m3}) << "\n";
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