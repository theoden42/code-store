
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


void rundfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, int m){

	vis[i][j] = 1;
	if(!vis[(i + 1) % 2][j] && grid[(i + 1) % 2][j] == 1){
		rundfs((i + 1) % 2, j, vis, grid, m);
	}
	else if(j < m - 1 && grid[i][j + 1] == 1 && !vis[i][j + 1]){
		rundfs(i, j + 1, vis, grid, m);
	}
	return;
}

void solve() {
    int m;
    cin >> m;
    string s1, s2;
    cin >> s1 >> s2;
    vector<vector<int>> grid(2, vector<int>(m, 0));

    for(int i = 0; i < m; i++){
    	if(s1[i] == 'B'){
    		grid[0][i] = 1;
    	}
    	if(s2[i] == 'B'){
    		grid[1][i] = 1;
    	}
    }

    vector<vector<int>> vis(2, vector<int>(m, 0));

    for(int i = 0; i < m; i++){

    	if(grid[0][i] == 1 && grid[0][i] == 1){

    		rundfs(0, i, vis, grid, m);
    		int flag = 1;
    		for(int i1 = 0; i1 < 2; i1++){
    			for(int j1 = 0; j1 < m; j1++){
    				if(grid[i1][j1] == 1 && vis[i1][j1] == 0){
    					flag = 0;
    				}
    			}
    		}
    		if(flag == 1){
    			cout << "YES\n";
    			return;
    		}

    		for(int i1 = 0; i1 < 2; i1++){
    			for(int j1 = 0; j1 < m; j1++){
    				vis[i1][j1] = 0;
    			}
    		}

    		rundfs(1, i, vis, grid, m);
    		flag = 1;
    		for(int i1 = 0; i1 < 2; i1++){
    			for(int j1 = 0; j1 < m; j1++){
    				if(grid[i1][j1] == 1 && vis[i1][j1] == 0){
    					flag = 0;
    				}
    			}
    		}
    		if(flag == 1){
    			cout << "YES\n";
    			return;
    		}
    		break;
    	}


    	else if(grid[0][i] == 1){

    		rundfs(0, i, vis, grid, m);
    		int flag = 1;
    		for(int i1 = 0; i1 < 2; i1++){
    			for(int j1 = 0; j1 < m; j1++){
    				if(grid[i1][j1] == 1 && vis[i1][j1] == 0){
    					flag = 0;
    				}
    			}
    		}

    		if(flag == 1){
    			cout << "YES\n";
    			return;
    		}
    		break;
    	}

    	else if(grid[1][i] == 1){

    		rundfs(1, i, vis, grid, m);
    		int flag = 1;
    		for(int i1 = 0; i1 < 2; i1++){
    			for(int j1 = 0; j1 < m; j1++){
    				if(grid[i1][j1] == 1 && vis[i1][j1] == 0){
    					flag = 0;
    				}
    			}
    		}

    		if(flag == 1){
    			cout << "YES\n";
    			return;
    		}
    		break;
    	}
    }

    cout << "NO\n";

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