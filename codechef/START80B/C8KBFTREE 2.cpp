
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

void dfs(int source, int xr, int parent, vector<int>& value, vector<vector<pair<int,int>>>& adj){
	value[source] = xr;
	for(auto& x: adj[source]){
		int vertex = x.first;
		int weight = x.second;
		if(vertex == parent)continue;

		dfs(vertex, xr ^ weight, source, value, adj);
	}


}

void solve() {
	int n;
	cin >> n;
	vector<vector<pair<int,int>>> adj(n);
	for(int i = 0; i < n - 1; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<int> xrs(n, 0);
	dfs(0, 0, -1, xrs, adj);

	map<int, pair<int,int>> mp;

	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			int weight = (xrs[i] ^ xrs[j]);
			if(mp.find(weight) == mp.end()){
				mp[weight] = {i, j};
			}
			else{
				cout << i + 1 << " " << j + 1 << " " << mp[weight].first + 1 << " " << mp[weight].second + 1 << "\n";
				return;
			}
		}
	}
	cout << "-1\n";

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