
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

const int MAX_INT = 1e9 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


int dfs(int source, vector<vector<int>>&g, vector<int>& vis, vector<int>& pos){
	debug(source);
	debug(pos);	
	vis[source] = 1;
	int flag = 0;
	for(int i = 0; i < 9; i++){
		if(pos[i] != -1 && pos[i] != i)flag = 1;
	}
	if(!flag)return 0;

	int count = MAX_INT;
	for(auto& x: g[source]){
		if(!vis[x]){
			swap(pos[x], pos[source]);
			count = min(count, 1 + dfs(x, g, vis, pos));
			swap(pos[x], pos[source]);
		}
	}
	return count;
}

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> g(9);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> pos(8, 0);
    vector<int> curpos(9, -1);   
    vector<int> vis(9, 0); 

    for(int i = 0; i < 8; i++){
    	cin >> pos[i];
    	pos[i]--;
    	curpos[pos[i]] = i;
    }

    int ind = -1;
    for(int i = 0; i < 9; i++){
    	if(curpos[i] == -1){
    		ind = i;
    		break;
    	}
    }
    debug(curpos);

    int ans = dfs(ind, g, vis, curpos);
    if(ans == MAX_INT){
    	cout << "-1\n";
    	return;
    }
    cout << ans << "\n";

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