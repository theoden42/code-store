
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const int INF = 1e9;
const ld EPS = 1e-9;

vector<pair<int,int>> moves = 
{{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};

int bfs(int i, int j, int i2, int j2){
	vector<vector<int>> d(8, vector<int> (8, 0));
	vector<vector<int>> vis(8, vector<int> (8, false));
	vis[i][j] = 1;
	queue<pair<int,int>> q;
	q.push({i, j});
	while(!q.empty()){
		pair<int,int> cur_cell = q.front();
		q.pop();
		vis[cur_cell.first][cur_cell.second] = 1;
		for(auto& m : moves){
			int x = cur_cell.first + m.first;
			int y = cur_cell.second + m.second;
			if(x >= 0 &&  x < 8 &&  y >= 0 && y < 8 && !vis[x][y]){
				q.push({x ,y});
				d[x][y] = d[cur_cell.first][cur_cell.second] + 1;  
				vis[x][y] = 1;
			}
		}
	}
	return d[i2][j2];
}

void solve() {
    string a, b;
    cin >> a >> b;
    int y1 = a[0] - 'a';
    int y2 = b[0] - 'a';
    int x1 = '8' - a[1];
    int x2 = '8' - b[1];
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    cout << bfs(x1, y1, x2, y2) << "\n";
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