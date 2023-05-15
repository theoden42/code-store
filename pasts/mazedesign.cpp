
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

vector<pair<int,int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int n){
	// cout << i << " " << j << ",,,,,\n";
	vis[i][j] = 1;
	if(grid[i][j] == 1){
		return 0;
	}
	if(j == n - 1)
		return 1;
	int k1 = i;
	int k2 = j;
	int y = 0;
	for(auto& x: dir){
		// cout << x.first << " " << x.second << ",,\n";
		k1 = i + x.first;
		k2 = j + x.second;
		if((k1 < 3 && k1 >= 0) && (k2 < n && k2 >= 0) && !vis[k1][k2]){
			y = (y | dfs(k1, k2, grid, vis, n));
		}
	}
	return y;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> grid(3, vector<int> (n, 0));
    for(int i = 0; i < 3; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < n; j++){
    		grid[i][j] = s[j] - '0';
    	}
    }
    vector<vector<int>> vis(3, vector<int>(n, 0));
    int f1, f2, f3;
    f1 = dfs(0, 0, grid, vis, n);

    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < n; j++){
    		vis[i][j] = 0;
    	}
    }
    f2 = dfs(1, 0, grid, vis, n);

    for(int i = 0; i < 3; i++){
    	for(int j = 0; j < n; j++){
    		vis[i][j] = 0;
    	}
    }

    f3 = dfs(2, 0, grid, vis, n);
    if(f1 || f2 || f3){
    	cout << "Solvable!" << "\n";
    }
    else{
    	cout << "Unsolvable!" << "\n";
    }
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