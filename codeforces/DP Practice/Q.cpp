
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


int dfs1(int source, vector<vector<pair<int,int>>>& adj, int parent, vector<int>& s_dist){
	int ans = 0;

	for(auto& x: adj[source]){
		if(x.first == parent)continue;
		ans += x.second + dfs1(x.first, adj, source, s_dist);
	}

	return s_dist[source] = ans;
}

void dfs2(int source, vector<vector<pair<int,int>>>& adj, int parent, int connected, vector<int>& dp){

	if(parent != -1){
		dp[source] = dp[parent] - ((connected) ? 1 : -1);
	}

	for(auto& x: adj[source]){
		if(x.first != parent){
			dfs2(x.first, adj, source, x.second, dp);
		}
	}
}


void solve() {
	int n;
	cin	>> n;
	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		adj[u].push_back({v, 0});
		adj[v].push_back({u, 1});
	}

	vector<int> s_dist(n);	
	vector<int> dp(n);

	dfs1(0, adj, -1, s_dist);

	dp[0] = s_dist[0];
	dfs2(0, adj, -1, 0, dp);

	int mn = INF;
	for(int i = 0; i < n; i++){
		mn = min(mn, dp[i]);
	}
	cout << mn << "\n";

	for(int i = 0; i < n; i++){
		if(dp[i] == mn){
			cout << i + 1 << " ";
		}
	}
	cout << endl;

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