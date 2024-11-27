

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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    }
    vector<int> vis(n + 1), dis(n + 1, 1e9 + 5);	
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    int mn = 1e9 + 5;
    vis[1] = 1;
    while(!q.empty()){
    	auto x = q.front();
    	q.pop();
    	for(auto y: adj[x]){
    		dis[y] = min(dis[y], dis[x] + 1);
    		if(!vis[y]){
    			q.push(y);
    			vis[y] = 1;
    		}
    		if(y == 1){
    			mn = min(mn, dis[x] + 1);
    		}
    	}
    }
    if(mn == 1e9 + 5){
    	cout << "-1\n";
    } else {
    	cout << mn << "\n";
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}