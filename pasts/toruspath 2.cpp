
/* @uthor: (g)theoden42 */


/*
 lets see what are we doing here: 
 we have got an N * N matrices, the question is can we visit all the cells
 x x x x x x 
 x x x ? x x
 x x x x x x
 x x x x x x
 x x x x x x
 x x x x x x 

*/
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
    vector<vector<int>> g(n, vector<int>(n, 0));
    ll sum = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		cin >> g[i][j];
    	}
    }

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		sum += g[i][j];
    	}
    }

    if(n == 2){
        cout << max({sum - g[0][n - 1], sum - g[n - 1][0]}) << "\n";
        return;
    }

    int mn = 1e9;
    for(int i = 0; i < n; i++){
        mn = min(mn, g[i][n - 1 - i]);
    }
    debug(mn, sum);
    cout << sum - mn << "\n";

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