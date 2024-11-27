
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
    int m, n, p;
    cin >> m >> n >> p;
    vector<vector<int>> steps(m, vector<int>(n, 0));
    for(int i = 0; i < m; i++){
    	for(int j = 0; j < n; j++){
    		cin >> steps[i][j];
    	}
    }

    ll count = 0;
    for(int i = 0; i < n; i++){
    	int mx = 0;
    	for(int j = 0; j < m; j++){
    		mx = max(mx, steps[j][i]);
    	}
    	count += mx - steps[p - 1][i];
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
         cout << "Case #" << t << ": ";
        solve();
    }
}