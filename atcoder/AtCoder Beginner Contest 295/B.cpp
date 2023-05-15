
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


void bfs(int i, int j, vector<vector<char>>& grid){
	int r = grid.size();
	int c = grid[0].size();
	int val = grid[i][j] - '0';
	for(int x = 0; x < r; x++){
		for(int y = 0; y < c; y++){
			if(grid[x][y] == '#' && abs(x - i) + abs(y - j) <= val){
				grid[x][y] = '.';
			}
		}
	}
    grid[i][j] = '.';
}

void solve() {
    int r, c;
    cin >> r >> c;
    vector<vector<char>> grid(r, vector<char>(c));
    for(int i = 0; i < r; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < c; j++){
    		grid[i][j] = s[j];
    	}
    }

    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		if(grid[i][j] != '.' && grid[i][j] != '#'){
    			bfs(i, j, grid);
    		}
    	}
    }

    for(int i = 0; i < r; i++){
    	for(int j = 0; j < c; j++){
    		cout << grid[i][j];
    	}
    	cout << "\n";
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