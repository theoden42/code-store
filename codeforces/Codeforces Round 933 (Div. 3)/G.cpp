

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
    int n, m;
    cin >> n >> m;

    map<int,set<int>> mp;

   	for(int i = 0; i < m; i++){
   		int u, v, c;
   		cin >> u >> v >> c;
   		mp[c].insert(u);
   		mp[c].insert(v);
   	}

   	int b, e;
   	cin >> b >> e;

   	if(b == e){
   		cout << "0\n";
   		return;
   	}

   	int sz;
   	sz = n + mp.size();
   	vector<vector<int>> adj(sz + 1);
   	int count = n + 1;

   	vector<int> src, dest;

   	for(auto& [it, v]: mp){
   		for(auto nd: v){
   			adj[count].push_back(nd);
   			adj[nd].push_back(count);
   			if(nd == b){
   				src.push_back(count);
   			} 
   			if(nd == e){
   				dest.push_back(count);
   			}

   		}
   		count += 1;
   	}

   	queue<int> q;
   	vector<int> dis(sz + 1);
   	vector<int> vis(sz + 1);

   	for(auto x: src){
   		q.push(x);
   		dis[x] = 0;
   		vis[x] = 1;
   	}

   	while(!q.empty()){
   		auto node = q.front();
   		q.pop();

   		for(auto neighbour: adj[node]){
   			if(!vis[neighbour]){
   				dis[neighbour] = dis[node] + 1;
   				vis[neighbour] = 1;
   				q.push(neighbour);
   			}
   		}
   	}

   	int ans = 1e18;
   	for(auto x: dest){
   		int d = (dis[x] + 1) / 2;
   		ans = min(ans, d);
   	}

   	cout << ans + 1 << "\n";
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