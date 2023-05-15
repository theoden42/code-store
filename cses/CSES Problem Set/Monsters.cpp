

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

vector<pair<int,int>> dxy = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<char> moves = {'U', 'D', 'L', 'R'};

int check(int x, int y, vector<string>& g){
	int n = g.size();
	int m = g[0].size();

	if(x >= 0 && x < n && y >= 0 && y < m && g[x][y] != '#'){
		return true;
	}
	return false;
}

char mv(int i, int j, int i2, int j2){
	for(int k = 0; k < 4; k++){
		auto d = dxy[k];
		int ni = i2 + d.first;
		int nj = j2 + d.second;
		if(ni == i && nj == j){
			return moves[k];
		}
	}
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> g(n);

    vector<pair<int,int>> mon;
    int si = 0, sj = 0;

    for(int i = 0; i < n; i++){
    	string x;
    	cin >> x;
    	g[i] = x;
    	for(int j = 0; j < m; j++){
    		if(g[i][j] == 'A'){
    			si = i;
    			sj = j;
    		}
    		if(g[i][j] == 'M'){
    			mon.push_back({i, j});
    		}
    	}
    }


    queue<vector<int>> hero;
    queue<vector<int>> monsters;
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m));
    vector<vector<int>> dis(n, vector<int> (m, 1e9));
    vector<vector<int>> vis(n, vector<int>(m, 0));
	
    for(auto x: mon){
    	monsters.push({x.first, x.second, 0});
    	dis[x.first][x.second] = 0;
    	vis[x.first][x.second] = 1;
    }


    while(!monsters.empty()){
    	auto it = monsters.front();
    	monsters.pop();
    	for(auto d: dxy){

    		int nx = it[0] + d.first;
    		int ny = it[1] + d.second;
    		if(!check(nx, ny, g) || vis[nx][ny])continue;
    		vis[nx][ny] = 1;
    		dis[nx][ny] = it[2] + 1;
    		monsters.push({nx, ny, it[2] + 1});
    	}
    }


    if(dis[si][sj] == 0){
    	cout << "NO\n";
    	return;
    }
    hero.push({si, sj, 0});
    vis.assign(n, vector<int>(m, 0));

    int ansx = -1, ansy = -1;

    while(!hero.empty()){
    	auto it = hero.front();
    	hero.pop();

    	for(auto d: dxy){

    		if(it[0] == 0 || it[1] == 0 || it[0] == n - 1 || it[1] == m - 1){
    			ansx = it[0];
    			ansy = it[1];
    			break;
    		}

    		int nx = it[0] + d.first;
    		int ny = it[1] + d.second;
    		if(!check(nx, ny, g) || vis[nx][ny])continue;

    		int ds = it[2] + 1;
    		if(ds >= dis[nx][ny])continue;

    		parent[nx][ny] = {it[0], it[1]};
    		vis[nx][ny] = 1;
    		hero.push({nx, ny, ds});
    	}	
    }



    if(ansx == -1 && ansy == -1){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";


    vector<char> seq;
    while(ansx != si || ansy != sj){
    	int px = parent[ansx][ansy].first;
    	int py = parent[ansx][ansy].second;
    	seq.push_back(mv(ansx, ansy, px, py));
    	ansx = px;
    	ansy = py;
    }

    reverse(all(seq));
    cout << seq.size() << "\n";
    for(auto& c: seq){
    	cout << c;
    }
    cout << endl;

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}