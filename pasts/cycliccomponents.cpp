
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

int checkcycle(int source, int parent, vector<vector<int>>& g, int start){
	debug(source, g[source]);

	if(g[source].size() != 2)return false;

	if(source == start)return true;


	for(auto& x: g[source]){
		if(x != parent){
			return checkcycle(x, source, g, start);
		}
	}
	return false;
}

void dfs(int source, vector<int>& vis, vector<vector<int>>& g){
	vis[source] = 1;
	for(auto& x: g[source]){
		if(!vis[x]){
			dfs(x, vis, g);
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    int count = 0;
    vector<int> vis(n, 0);
    for(int i = 0; i < n; i++){
    	if(vis[i])continue;
    	if(g[i].size() == 2 && checkcycle(g[i][0], i, g, i)){
    		count++;
    		debug(i);
    	}
    	dfs(i, vis, g);
    }
    cout << count << "\n";	
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