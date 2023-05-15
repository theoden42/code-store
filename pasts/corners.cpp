
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    int count = 0;

    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		grid[i][j] = s[j] - '0';
            if(grid[i][j])count++;
    	}
    }
    debug(count);
    int mx = 0;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            int x = 0;
            int op = 0;
            x += grid[i][j + 1];
            x += grid[i][j];
            x += grid[i + 1][j];
            x += grid[i + 1][j + 1];
            debug(i, j, x);

            if(x > 1) op = 2;
            else if(x == 0) op = 0;
            else op = 1;

            int total = count - x + op;
            mx = max(mx, total);
        }

    }
    cout << mx << "\n";    
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