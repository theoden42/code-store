

/* author: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> adj(n + 1);
    int pop = 0;
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    	pop += a[i];
    }
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> sum(n + 1);
    int temp = 0;	
    function<int(int,int,int)> dfs =
     [&](int src, int pnt, int lev){
     	sum[src] += a[src];
     	temp += a[src] * lev;
     	for(auto x: adj[src]) if(x != pnt){
     		sum[src] += dfs(x, src, lev + 1);
     	}
     	return sum[src];
    }; dfs(1,1,0);

    vector<int> ans(n + 1);
    function<void(int,int)> reroot =
    [&](int src, int pnt){
		ans[src] += temp;
		for(auto x: adj[src]) if(x != pnt){
			temp -= sum[x];
			temp += (pop - sum[x]);
			reroot(x, src);
			temp += sum[x];
			temp -= (pop - sum[x]);
		}
    }; reroot(1,1);
    for(int i = 1; i <= n; i++){
    	cout << ans[i] << " \n"[i == n];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
    	solve();
    }

}