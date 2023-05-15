
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

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n;
vector<int> parent(1e5 + 5, -1);
vector<int> sz(1e5 + 5);
	

int getParent(int a){
	return (parent[a] == a)? a : getParent(parent[a]);
}

void uni(int a, int b){
	debug(a, b);
 	int x = getParent(a);
 	int y = getParent(b);
 	if(sz[x] >= sz[y]){
 		parent[y] = x;
 		sz[x] += sz[y];
 		sz[y] = 0;
 	}
 	else{
 		parent[x] = y;
 		sz[y] += sz[x];
 		sz[x] = 0;
 	}
}


void dfs(int source, vector<int>& vis, vector<vector<int>>& g){
	vis[source] = 1;
	for(auto& x: g[source]){
		if(vis[x])continue;
		uni(source, x);
		dfs(x, vis, g);
	}
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;y--;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }

    debug(g);

    for(int i = 0; i < n; i++){
    	parent[i] = i;
    	sz[i] = 1;
    }

    vector<int> vis(n, 0);

    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		dfs(i, vis, g);
    	}
    }

    map<int,int> mp;
    vector<int> ans;
    for(int i = 0; i < n; i++){
    	int x = getParent(i);
    	if(mp.find(x) == mp.end()){
    		ans.push_back(x);
    		mp[x] += 1;
    	}
    }


    cout << ans.size() - 1 << "\n";
    for(int i = 0; i < ans.size() - 1; i++){
    	cout << ans[i] + 1 << " " << ans[i + 1] + 1 << "\n";
    }
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