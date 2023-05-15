
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


int findsubtree(int source, vector<int>& vis, vector<vector<int>>& g, vector<int>& subtree){
	vis[source] = 1;
	subtree[source] = 1;
	for(auto& x: g[source]){
		if(!vis[x]){
			subtree[source] += findsubtree(x, vis, g, subtree);
		}
	}
	return subtree[source];
}

int dfs(int source, int parent, vector<vector<int>>& g, vector<int>& subtree){

	int mx = 0;
	for(auto& x: g[source]){
		if(x == parent)continue;
		for(auto& y: g[source]){
			if(x == y || parent == y)continue;

			mx = max(mx, dfs(y, source, g, subtree) + subtree[x] - 1);
		}
	}

	if(mx == 0){
		for(auto& x: g[source]){
			if(x != parent)mx = max(mx, subtree[x] - 1);
		}
	}

	debug(source, mx);
	return mx;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 1; i <= n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }

    vector<int> vis(n, 0);
    vector<int> subtree(n, 0);


    subtree[0] = findsubtree(0, vis, g, subtree);

    debug(subtree);

    for(int i = 0; i < n; i++){
    	vis[i] = 0;
    }

    cout << dfs(0, -1, g, subtree) << "\n";


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