
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

void dfs(int source, vector<vector<int>>& g, vector<int>& dpth, vector<int>& vis, int k){
	vis[source] = 1;
	dpth[k]++;
	for(auto& x: g[source]){
		if(vis[x])continue;
		dfs(x, g, dpth, vis, k + 1);
	}
}


void solve() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for(int i = 1; i <= n - 1; i++){
    	int x, y;
    	cin >> x >> y;
    	x--;
    	y--;
    	g[x].push_back(y);
    	g[y].push_back(x);
    }
    int sum = q;
    for(int i = 0; i < q; i++){
    	int x;
    	cin >> x;
    }
    vector<int> vis(n, 0);
    vector<int> dpth(n, 0);
    int k = 0;
    dfs(0, g, dpth, vis, 0);

    ll prefix = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
    	prefix += dpth[i];
    	if(dpth[i] == 0 || prefix > q){
    		break;
    	}
    	count += dpth[i];
    }
    cout << count << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
         cout << "Case #" << t << ": ";
        solve();
    }
}