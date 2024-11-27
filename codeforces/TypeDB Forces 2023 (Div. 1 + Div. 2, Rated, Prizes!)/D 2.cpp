/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
#define int long long


void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];

    }

    vector<vector<int>> adj(n + 2);
    for(int i = 1; i <= n; i++){
    	int t = a[i] + i;
    	if(t >= 1 && t <= n){
    		adj[t].push_back(i);
    		a[i] = t;
    	}
    	else{
    		adj[n + 1].push_back(i);	
    		a[i] = n + 1;
    	}
    }

    vector<int> vis(n + 2);
    vector<int> vis2(n + 2);

    function<void(int)> dfs = [&](int source){
    	vis[source] = 1;
    	for(auto& x: adj[source]){
    		if(!vis[x])
    			dfs(x);
    	}
    };

    vector<int> sz(n + 2);
    function<int(int)> cyclesz = [&](int source)->int{
    	sz[source] = 1;
    	vis2[source] = 1;
    	for(auto& x: adj[source]){
    		sz[source] += (vis2[x]) ? 0 : cyclesz(x);
    	}
    	return sz[source];
    };



    dfs(n + 1);
    cyclesz(n + 1);

    int con = 0;
    for(int i = 1; i <= n + 1; i++){
    	if(vis[i])con++;
    }

    // debug(sz);

    if(vis[1]){
    	int ans = 0;
    	ans += (2 * n + 1) * (n - con + 1);

    	int x = 1;
    	int cnt = 0;
    	while(x != n + 1){
    		cnt++;
    		ans += n + 1;
    		ans += (con - 1 - sz[x]);
    		x = a[x];
    	}
    	ans += (con - cnt - 1) * (2 * n + 1);
    	cout << ans << "\n";
    }
    else{
    	int ans = 0;

    	vector<int> rchd(n + 2);
    	int x = 1;
    	int cnt = 0;
    	while(1){
    		if(rchd[x])break;
    		cnt++;
    		rchd[x] = 1;
    		x = a[x];
    	}
    	ans += cnt * (n + 1);
    	ans += cnt * (con - 1);
    	cout << ans << "\n";
    }

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}