
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

void filldepth(int src, vector<vector<int>>& g, vector<int>& vis, vector<int>& depth, int dth){
	vis[src] = 1;
	depth[src] = dth;
	for(auto& x: g[src]){
		if(!vis[x]){
			filldepth(x, g, vis, depth, dth + 1);
		}
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

   	vector<int> depth(n);
   	vector<int> vis(n, 0);

   	int src = 0;
   	for(int i = 0; i < n; i++){
   		if(g[i].size() <= 2){
   			src = i;

   		}
   	}

   	filldepth(src, g, vis, depth, 0);

   	for(int i = 0 ; i < q; i++){
   		int x, y;
   		cin >> x >> y;
   		x--;
   		y--;
   		ll ans = 20 * (abs(depth[x] - depth[y]));
   		cout << ans << "\n";
   	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}