#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, x;
	cin >> n >> m >> x;
	vector<pair<int,int>> triples;
	for(int i = 1; i <= x; i++){
		for(int j = 1; j <= x; j++){
			int sum = i * i + j * j;
			if(sum == x * x){
				triples.push_back({i, j});
			}
		}
	}

	int sx, sy;
	int dx, dy;

	cin >> sx >> sy;
	cin >> dx >> dy;

	sx -= 1;
	sy -= 1;
	dx -= 1;
	dy -= 1;

	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<vector<int>> dis(n, vector<int>(m, 1e9));

	auto check = [&](int i, int j){
		return (i >= 0 && i < n && j >= 0 && j < m);
	};

	queue<pair<int,int>> q;
	q.push({sx, sy});
	while(!q.empty()){
		auto [i, j] = q.front();
		q.pop();
		int ni1, nj1, ni2, nj2, ni3, nj3, ni4, nj4;
		for(auto [di, dj]: triples){
			ni1 = i + di;
			nj1 = j + dj;

			ni2 = i - di;
			nj2 = j + dj;

			ni3 = i - di;
			nj3 = j - dj;

			ni4 = i + di;
			nj4 = j - dj;

			if(check(ni1, nj1) && !vis[ni1][nj1]){
				dis[ni1][nj1] = dis[i][j] + 1;
				q.push({ni1, nj1});
			}
		}
	}
	if(dis[dx][dy] == 1e9){
		cout << "-1\n";
	} else {
		cout << dis[dx][dy];
	}
}