

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
   	int n, a, b;
   	cin >> n >> a >> b;
   	vector<vector<int>> adj(n + 1);
   	for(int i = 1; i <= n; i++){
   		int u, v;
   		cin >> u >> v;
   		adj[u].push_back(v);
   		adj[v].push_back(u);
   	}

    if(a == b){
        cout << "NO\n";
        return;
    }

   	vector<int> cycle;
   	vector<int> components;
   	vector<int> vis(n + 1);

   	function<int(int, int)> dfs = [&](int source, int parent){
   		vis[source] = 1;
   		for(auto x: adj[source]){
            if(x == parent)
                continue;
            if(vis[x]){
                cycle.push_back(source);
                cycle.push_back(x);
                for(int i = components.size() - 1; i >= 0 && components[i] != x; i--){
                    cycle.push_back(components[i]);
                }
                return true;
            } 
            components.push_back(source);
            if(dfs(x, source)){
                components.pop_back();
                return true;
            }
            components.pop_back();
   		}

        return false;
   	};
   	dfs(1, -1);


   	queue<int> q;
   	q.push(a);
   	vis.assign(n + 1, 0);
   	vector<int> dis(n + 1);
   	dis[a] = 0;
   	vis[a] = 1;
   	while(!q.empty()){
   		auto node = q.front();
   		q.pop();
   		for(auto x: adj[node]){
   			if(vis[x])
   				continue;
   			vis[x] = 1;
   			dis[x] = dis[node] + 1;
   			q.push(x);
   		}
   	}
   	// debug(dis);

   	queue<int> q2;
   	q2.push(b);
   	vis.assign(n + 1, 0);
   	vector<int> dis2(n + 1);
   	dis2[b] = 0;
   	vis[b] = 1;
   	while(!q2.empty()){
   		auto node = q2.front();
   		q2.pop();
   		for(auto x: adj[node]){
   			if(vis[x] || dis[x] <= dis2[node] + 1)
   				continue;
   			vis[x] = 1;
   			dis2[x] = dis2[node] + 1;
   			q2.push(x);
   		}
   	}


   	for(auto c: cycle){
   		if(vis[c]){
   			cout << "YES\n";
   			return;
   		}
   	}

   	cout << "NO\n";

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