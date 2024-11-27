
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

void dfs(int source, vector<int>& vis, vector<vector<int>>& adj, vector<int>& vertex){
	vertex.push_back(source);
	vis[source] = 1;
	for(auto& x: adj[source]){
		if(!vis[x]){
			dfs(x, vis, adj, vertex);
		}
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> vis(n, 0);


    auto check = [&](vector<int>& vertex){
    	int count = 0;
    	int sz = vertex.size();

    	for(auto& x: vertex){
    		count += (int)adj[x].size();
    	}

    	if(count / 2 == sz){
    		return true;
    	}
    	return false;
    };

    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		vector<int> vertex;
    		dfs(i, vis, adj, vertex);
    		if(check(vertex)){
                continue;
    		}
            else{
                cout << "No\n";
                return;
            }
    	}
    }
    cout << "Yes\n";
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