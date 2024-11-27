

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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(k);
    for(int i = 0; i < k; i++){
    	cin >> x[i];
    }
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    queue<int> q;
    vector<int> vis(n + 1);
    vector<int> dis(n + 1, INF);
    for(auto xin: x){
    	q.push(xin);
    	dis[xin] = 0;
    }
    while(!q.empty()){
    	auto nd = q.front();
    	q.pop();
    	for(auto newnd: adj[nd]){
    		if(vis[newnd])
    			continue;
    		vis[newnd] = 1;
    		dis[newnd] = min(dis[newnd], dis[nd] + 1);
    		q.push(newnd);
    	}
    }

    int count = 0;
    int flag = 0;
    function<void(int, int, int)> dfs = [&](int source, int parent, int currdis){
    	if(dis[source] <= currdis){
    		count++;
    		return;
    	}
    	if(adj[source].size() == 1 && source != 1){
    		flag = 1;
    		return;
    	}
    	for(auto x: adj[source]){
    		if(x == parent)
    			continue;
    		dfs(x, source, currdis + 1);
    	}
    };

    dfs(1, -1, 0);

    if(flag){
    	cout << "-1\n";
    	return;
    }
    cout << count << endl;
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