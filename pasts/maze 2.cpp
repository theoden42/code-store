
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

int n, m, k;
vector<vector<char>> grid(600, vector<char> (600));
vector<vector<int>> vis(600, vector<int> (600, 0));
map<pair<int,int>, int> mp;

vector<pair<int,int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int dfs(int i , int j){
	// if(vis[i][j]){
	// 	return mp[{i,j}];
	// }
	// cout << i << " " << j << "\n";
	vis[i][j] = 1;
	int d = 0;
	for(auto& x: dir){
		int l1 = i + x.first;
		int l2 = j + x.second;
		if(l1 >= 0 && l1 < n && l2 >= 0 && l2 < m){
			if(vis[l1][l2])
				continue;
			if(grid[l1][l2] != '#'){
				d += dfs(l1, l2);
			}
		}
	}
	mp[{i, j}] = d + 1;
	return d + 1;
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < m; j++){
    		grid[i][j] = s[j];
    	}
    }
    int flg = 1;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(grid[i][j] != '#'){
    			mp[{i,j}] = dfs(i, j);
    			flg = 0;
    			break;
    		}
    	}
    	if(flg == 0)
    		break;
    }
    vector<pair<int,pair<int,int>>> vp(n * m);
    int i = 0;
    for(auto& x: mp){
    	vp[i].first = x.second;
    	vp[i].second = x.first;
    	i++;
    }
    sort(all(vp));
    // for(int i = 0; i < n * m; i++){
    // 	cout << vp[i].first << " " << vp[i].second.first << " " << vp[i].second.second << "\n";
    // }
    int x = k;
    for(int i = 0; i < n * m; i++){
    	if(x == 0)
    		break;
    	if(vp[i].first != 0){
    		grid[vp[i].second.first][vp[i].second.second] = 'X';
    		x--;
    	}

    }
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
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