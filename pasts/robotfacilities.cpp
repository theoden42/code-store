
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

int bfs(int i, int j, int n, int m, vector<vector<int>>& fact, vector<vector<int>>& vis){
	
	queue<pair<int,int>> q;
	q.push({i, j});
	int count = 0;


	while(!q.empty()){

		count += 1;
		pair<int,int> x = q.front();
		int i = x.first;
		int j = x.second;



		int temp = fact[i][j];
		vis[i][j] = 1;
		q.pop();

		int west = (temp & 1);
		temp = temp >> 1;
		int south = (temp & 1);
		temp = temp >> 1;
		int east = (temp & 1);
		temp >>= 1;
		int north = (temp & 1);

		if(!west && !vis[i][j - 1]){
			q.push({i, j - 1});
		}
		
		if(!south && !vis[i + 1][j]){
			q.push({i + 1, j});
		}

		if(!east && !vis[i][j + 1]){
			q.push({i, j + 1});
		}

		if(!north && !vis[i - 1][j]){
			q.push({i - 1, j});
		}
	}
	return count;
}

// int dfs(int i, int j, int n, int m, vector<vector<int>>& fact, vector<vector<int>>& vis){
// 	int count = 1;
// 	vis[i][j] = 1;

// 	int x = fact[i][j];
// 	int temp = x;

// 	int west = (temp & 1);
// 	temp >>= 1;
// 	int south = (temp & 1);
// 	temp >>= temp 1;
// 	int east = (temp & 1);
// 	temp >>= 1;
// 	int north = (temp & 1);

// 	if(!west && !vis[i][j - 1]){
// 		count += dfs(i, j - 1, n, m, fact, vis);
// 	}
// 	if(!south && !vis[i + 1][j]){
// 		count += dfs(i + 1, j, n, m, fact, vis);
// 	}
// 	if(!east && !vis[i][j + 1]){
// 		count += dfs(i, j + 1, n, m, fact, vis);
// 	}
// 	if(!north && !vis[i - 1][j]){
// 		count += dfs(i - 1, j, n, m, fact, vis);
// 	}
// 	return count;
// }

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> fact(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> fact[i][j];
		}
	}

	vector<int> roomsize;
	vector<vector<int>> vis(n, vector<int>(m, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(!vis[i][j]){
				roomsize.push_back(bfs(i, j, n, m, fact, vis));
			}
		}
	}
	sort(roomsize.rbegin(), roomsize.rend());
	for(auto& x: roomsize){
		cout << x << " ";
	}
	cout << "\n";
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