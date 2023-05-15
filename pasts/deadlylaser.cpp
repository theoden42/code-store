
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
    int n, m, sx, sy, d;
    cin >> n >> m >> sx >> sy >> d;
    int rex = sy + d;
    int lex = sy - d;
    int tex = sx - d;
    int bex = sx + d;
    if(abs(n - sx) + abs(m - sy) <= d){
    	cout << -1 << "\n";
    	return;
    }
    if(rex < m && tex > 1){
    	cout << n + m - 2<< "\n";
    }
    else if(lex > 1 && bex < n){
    	cout << n + m - 2 << "\n";
    }
    else{
    	cout << -1 << "\n";
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