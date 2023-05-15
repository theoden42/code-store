
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

int dfs(int v, vector<vector<int>>& adj, vector<int>& level, vector<int>& nchild, vector<int>& vis){
	vis[v] = 1;
	for(auto& x: adj[v]){
		if(!vis[x]){
			level[x] = level[v] + 1;
			nchild[v] += dfs(x, adj, level, nchild, vis);
		}
	}
    return nchild[v];
}

void solve() {
    int n, k;
    cin >> n >> k;
    // if(n - 1 == k){
    //     cout << n - 1 << "\n";
    //     return;
    // }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
        u--;
        v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> level(n , 0);
    vector<int> vis(n , 0);
    vector<int> nchild(n, 1);
    dfs(0, adj, level, nchild, vis);
    vector<int> fl(n);
    for(int i = 0; i < n; i++){
        fl[i] = level[i] - nchild[i] + 1;
    }
    // for(int i = 0; i < n; i++){
    //     cout << i << " " << level[i] << " " << nchild[i] << " " << fl[i] << "\n";
    // }
    // for(int i = 0; i < n; i++){
    //     cout << i << " " << fl[i] << "\n";
    // }
    sort(all(fl));
    ll sum = 0;
    for(int i = n - 1; i >= n - k; i--){
    	sum +=  fl[i];
        // cout << i << " " << fl[i] << "\n";
    }
    cout << sum << "\n";
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