
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

void dfs(int source, vector<vector<int>>& adj, vector<int>& vis, vector<int>& temp){
	temp.push_back(source);
	vis[source] = 1;
	for(auto& x: adj[source]){
		if(!vis[x]){
			dfs(x, adj, vis, temp);
		}
	}
}

ll countedges(int source, vector<vector<int>>& adj, vector<vector<int>>& mat){	
	vector<int> temp;

	int n = adj.size();
	vector<int> vis(n, 0);
	dfs(source, adj, vis, temp);	


	ll count = 0;
	for(auto& x: temp){
		if(mat[source][x] == -1 && source != x){
			count++;
		}
	}
	return count;

}

void solve() {
    int n, m;
    cin >> n >> m;


    vector<vector<int>> adj(n);
    vector<vector<int>> mat(n, vector<int>(n, -1));

    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	mat[u][v] = 1;
    }



    ll count = 0;


    for(int i = 0; i < n; i++){
    	count += countedges(i, adj, mat);
    }

    cout << count << "\n";

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