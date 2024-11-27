
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<int> dp(3e5, -1);

int dfs(int source, vector<vector<int>>& g, vector<int>& vis){
	vis[source] = 1;
	int count = 1;
	for(auto& x: g[source]){
		if(vis[x])continue;
		count += dfs(x, g, vis);
	}
	vis[source] = 0;

	if(count > 1e7){
		cout << 1000000 << "\n";
		exit(0);
	}
	return count;

}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    vector<int> vis(n, 0);
    int count = dfs(0, g, vis);
    cout << min(count, (int)1e6)<< "\n";
    
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