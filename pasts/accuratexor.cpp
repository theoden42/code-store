
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

int dfs(int source, vector<bool>& vis, vector<vector<int>>& g, int& k, vector<int>& ans){
	vis[source] = true;
	int xr = 0;
	for(auto& x: g[source]){
		if(!vis[x]){
			xr = (xr ^ dfs(x, vis, g, k, ans));
		}
	}
	// cout << source << " " << xr  <<  " " << k << " "<< "\n";
	if(k > 0){
		if(xr == 0){
			ans[source] = 1;
			k--;
			return 1;
		}
		else{
			ans[source] = 0;
			k--;
			return 1;
		}
	}
	else{
		if(xr == 0){
			ans[source] = 0;
			return 0;
		}
		else{
			ans[source] = 1;
			return 0;
		}
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1);
    for(int i = 2; i <= n; i++){
    	int p;
    	cin >> p;
    	g[p].push_back(i);
    	g[i].push_back(p);
    }
	vector<bool> vis(n + 1, false);
	vector<int> ans(n + 1, -1);
	int v = dfs(1, vis, g, k, ans);
	for(int i = 1; i <= n; i++){
		cout << ans[i];
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