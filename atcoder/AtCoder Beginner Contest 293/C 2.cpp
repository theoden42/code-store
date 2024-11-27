
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


int f(int i, int j, vector<vector<int>>& grid, set<int>& st){
	int n = grid.size();
	int m = grid[0].size();

	if(i == n - 1 && j == m - 1){
		return 1;
	}

	int ans = 0;
	st.insert(grid[i][j]);

	if(i + 1 < n && j < m && st.find(grid[i + 1][j]) == st.end()){
		ans = f(i + 1, j, grid, st);
	}
	if(i < n && j + 1 < m && st.find(grid[i][j + 1]) == st.end()){
		ans += f(i, j + 1, grid, st);
	}

	st.erase(st.find(grid[i][j]));

	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}

	set<int> st;
	cout << f(0, 0, grid, st) << "\n";
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