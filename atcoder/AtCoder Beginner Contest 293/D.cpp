
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

int checkdfs(int i, vector<vector<int>>& adj, int parent, vector<int>& vis){
	vis[i] = 1;

	int ans = 0;
	for(auto& x: adj[i]){
		if(x == parent)continue;

		if(vis[x])

		if(checkdfs(x, adj, i, vis))return true;
	}
	return false;
}	

void solve() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> v(n, set<int>());


    vector<vector<int>> adj(n);

    for(int i = 1; i <= m; i++){
    	char b, d;
    	int a, c;
    	cin >> a >> b >> c >> d;

    	debug(a, b, c, d);
    	a--;
    	c--;


    	if(v[a].find(c) == v[a].end()){
    		adj[a].push_back(c);
    		adj[c].push_back(a);
    		v[a].insert(c);
    		v[c].insert(a);
    	} 
    }

    debug(adj);

    vector<int> vis(n, 0);


    int ca = 0;
    int cb = 0;


    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		if(checkdfs(i, adj, -1, vis)){
    			ca++;
    		}
    		else{
    			cb++;
    		}
    	}
    }
    cout << ca << " " << cb << endl;
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