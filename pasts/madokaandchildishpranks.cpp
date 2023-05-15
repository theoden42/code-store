
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
    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		grid[i][j] = s[j] - '0';
    	}
    }
    if(grid[0][0] == '1'){
    	cout << "-1" << "\n";
    	return;
    }
    vector<vector<int>> initial(n, vector<int> (m, 0));
    vector<vector<pair<int, int>>> op(n * m, vector<int>(2, 0));
    int count = 0;
    int k = 0;
    for(int i = 0; i < n; i++){
    	for(int j = m - 1; j >= 0; j--){
    		if(grid[i][j] == 1 && initial[i][j] == 0){
    			count++;
    			op[k][0] = {i + 1, j + 1};
    			op[k][1] = {i + 1, j + 2};
    			k++;
    		}
    	}
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