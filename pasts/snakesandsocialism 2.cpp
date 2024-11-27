
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

vector<pair<int,int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, 1}, {-1,-1},{1, -1}, {1, 1}};

vector<vector<int>> bfs(int n, int m, vector<vector<int>>& grid, vector<pair<int,int>>& sources){
	vector<vector<int>> level(n, vector<int> (m, INF));
	queue<pair<int,int>> q;
	for(auto& x : sources){
		q.push(x);
		level[x.first][x.second] = 0;
	}
	while(!q.empty()){
		pair<int,int> cur_v = q.front();
		q.pop();
		for(auto& x: d){
			pair<int,int> child = {cur_v.first + x.first, cur_v.second + x.second};
			if(child.first < n && child.second < m && child.first >= 0 && child.second >= 0){
				if(level[child.first][child.second] > level[cur_v.first][cur_v.second] + 1){
					level[child.first][child.second] = level[cur_v.first][cur_v.second] + 1;
					q.push(child);
				}
			}
		}
	}
	return level;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int ma = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> grid[i][j];
    		if(grid[i][j] > ma){
    			ma = grid[i][j];
    		}
    	}
    }
    vector<pair<int,int>> sources;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(grid[i][j] == ma){
    			sources.push_back({i, j});
    		}
    	}
    }
    vector<vector<int>> level = bfs(n, m, grid, sources);
    int mn = 0;
    for(auto& x : level){
    	for(auto& y : x){
    		mn = max(y, mn);
    	}
    }
    cout << mn << "\n";
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