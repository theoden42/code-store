

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

vector<vector<int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

void dfs(int i, int j, vector<vector<char>>& adj, vector<vector<int>>& vis, vector<pair<int,int>>& comp){
	vis[i][j] = 1;
	int n = adj.size();
	int m = adj[0].size();
	comp.push_back({i, j});

	for(auto d: dir){
		int x = i + d[0];
		int y = j + d[1];
		if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && adj[x][y] == '*'){
			dfs(x, y, adj, vis, comp);
		}
	}
}

int check(int i, int j, vector<vector<char>>& adj, vector<vector<int>>& vis){
	vector<pair<int,int>> comp;
	dfs(i, j, adj, vis, comp);


	if(comp.size() != 3)return false;


	do{
		if(comp[0].first == comp[1].first && comp[0].second == comp[2].second)return true;
	}while(next_permutation(all(comp)));

	return false;

}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<char>> grid(n, vector<char>(m));
	for(int i = 0; i < n; i++){
		string x;
		cin >> x;
		for(int j = 0; j < m; j++){
			grid[i][j] = x[j];
		}
	}

	vector<vector<int>> vis(n, vector<int>(m, 0));

	for(int i = 0; i < n; i++){
		for(int j =0; j < m; j++){
			if(!vis[i][j] && grid[i][j] == '*'){
				if(!check(i, j, grid, vis)){
					cout << "NO\n";
					return;
				}	
			}
		}
	}
	cout << "YES\n";
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