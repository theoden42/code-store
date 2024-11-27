

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long


vector<vector<int>> dis = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void solve() {
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	for(int i = 0; i < h; i++){
		cin >> g[i];
	}

	vector<vector<int>> row(h), col(w);
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(g[i][j] != '.'){
				row[i].push_back(j);
				col[j].push_back(i);
			}
		}
	}

	auto passable = [&](int i, int j){
		if(g[i][j] != '.' && g[i][j] != 'G' && g[i][j] != 'S')
			return false;

		auto r = upper_bound(all(row[i]), j);
		auto c = upper_bound(all(col[j]), i);

		if(r != row[i].begin()){
			--r;
			if(g[i][*r] == '>')
				return false;
			++r;
		}
		if(r != row[i].end()){
			if(g[i][*r] == '<')
				return false;
		}

		if(c != col[j].begin()){
			--c;
			if(g[*c][j] == 'v')
				return false;
			++c;
		}
		if(c != col[j].end()){
			if(g[*c][j] == '^')
				return false;
		}
		return true;
	};

	auto bfs = [&](int i, int j){
		vector<vector<int>> vis(h, vector<int> (w, 0));
		vector<vector<int>> distance(h, vector<int>(w, INF));
		queue<pair<int,int>> q;
		q.push({i, j});
		distance[i][j] = 0;
		while(!q.empty()){
			auto [i, j] = q.front();
			q.pop();	
			for(auto d: dis){
				int ni = d[0] + i;
				int nj = d[1] + j;
				if(ni >= 0 && ni < h && nj >= 0 && nj < w && !vis[ni][nj] && passable(ni, nj)){
					distance[ni][nj] = min(distance[ni][nj], distance[i][j] + 1);
					vis[ni][nj] = 1;
					q.push({ni, nj});
				}
			}
		}
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(g[i][j] == 'G'){
					if(distance[i][j] == INF)
						return -1ll;
					return distance[i][j];
				}
			}
		}
	};

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(g[i][j] == 'S'){
				int ans = bfs(i, j);
				cout << ans << "\n";
				return;
			}
		}
	}


}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}