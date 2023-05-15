
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


vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};


void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis){
	vis[i][j] = 1;

	int n = grid.size();
	int m = grid[0].size();

	for(auto d: dir){
		int r = i + d.first;
		int c = j + d.second;
		if(r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[i][j] != '#'){
			dfs(r, c, grid, vis);
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; ++i){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		grid[i][j] = s[j];
    	}
    }


    auto cover = [&](int i, int j){
    	debug(i, j);
    	for(auto& x: dir){
    		int r = i + x.first;
    		int c = j + x.second;
    		if(r >= 0 && r < n && c >= 0 && c < m){
    			if(grid[r][c] == 'G')return false;
    			
    			if(grid[r][c] == '.'){
    				grid[r][c] = '#';
    			}

    		}
    	}
    	return true;
    };

    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(grid[i][j] != 'B')continue;

    		if(cover(i, j)){
    			continue;
    		}
    		else{
    			cout << "No\n";
    			return;
    		}
    	}
    }


	vector<vector<int>> vis(n, vector<int>(m, 0));

	dfs(n - 1, m - 1, grid, vis);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] == 'G'){
				if(!vis[i][j]){
					cout << "No\n";
					return;
				}
			}
		}
	}

	cout << "Yes\n";
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