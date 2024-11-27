
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

void dfs(int source, vector<vector<int>>& g, vector<int>& vis, map<pair<int,int>, int>& mp, int val){
	vis[source] = 1;
	for(auto& x: g[source]){
		if(vis[x])continue;
		mp[{source, x}] = val;
		if(val == 2){
			dfs(x, g, vis, mp, 3);
		}else{
			dfs(x, g, vis, mp, 2);
		}
	}
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    vector<pair<int,int>> edges(n - 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    	edges[i] = {u, v}; 
    }


    for(int i = 1; i <= n; i++){
    	if(g[i].size() >= 3){
    		cout << "-1\n";
    		return;
    	} 
    }	

    int ind = 1;



    for(int i = 1; i <= n; i++){
    	if(g[i].size() == 1){
    		ind = i;
    		break;
    	}
    }

    debug(ind);

   	vector<int> vis(n + 1);
   	map<pair<int,int>, int> mp;
   	dfs(ind, g, vis, mp, 2);

   	debug(mp, edges);

   	for(int i = 0; i < n - 1; i++){
   		if(mp.find(edges[i]) != mp.end()){
   			cout << mp[edges[i]] << " ";
   		}
   		else{
   			cout << mp[{edges[i].second, edges[i].first}] << " ";
   		}
   	}
   	cout << "\n";
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