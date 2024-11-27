
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

vector<pair<int,int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int h, w;
int indx, indy;



int dfs(int ps, int x, int y, vector<vector<int>>& vis, vector<vector<char>>& g){
	if(x == indx && y == indy){
		if(ps >= 4){
			return 1;
		}
		else{
			return 0;
		}
	}

	if(x < 0 || x >= h || y < 0 || y >= w || g[x][y] == '#'){
		return 0;
	}

	vis[x][y] = 1;
	for(auto d: dir){
		int a = x + d.first; 
		int b = y + d.second;
		if(a >= 0 && a < h && b >= 0 && b < w && !vis[a][b] && g[a][b] != '#'){
			if (dfs(ps + 1, a, b, vis, g) == 1){
				return 1;
			}
		}
	}
	return 0;
}

void solve() {

    cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));


    for(int i = 0; i < h; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < w; j++){
    		g[i][j] = s[j];
    		if(s[j] == 'S'){
    			indx = i;
    			indy = j;
	    	}
    	}
    }

    int ans = 0;
    vector<vector<int>> vis(h, vector<int>(w, 0));
    ans = (ans | dfs(1, indx + 1, indy, vis, g));


    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		vis[i][j] = 0;
    	}
    }
    ans = (ans | dfs(1, indx - 1, indy, vis, g));

    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		vis[i][j] = 0;
    	}
    }
    ans = (ans | dfs(1, indx, indy + 1, vis, g));

    for(int i = 0; i < h; i++){
    	for(int j = 0; j < w; j++){
    		vis[i][j] = 0;
    	}
    }
    ans = (ans | dfs(1, indx, indy - 1, vis, g));


    if(ans)cout << "Yes\n";
    else cout << "No\n";	

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