

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
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> colors(n + 1);
    vector<int> vis(n + 1);
    colors[1] = 0;
    queue<pair<int,int>> q;
    q.push({1, 0});
    vis[1] = 1;
   	while(!q.empty()){
   		auto [nd, col] = q.front();
   		q.pop();
   		for(auto x: adj[nd]) if (!vis[x]){
   			colors[x] = 1 - col;
   			vis[x] = 1;
   			q.push({x, 1 - col});
   		}
   	}
   	vector<vector<int>> sets(3);
   	int flag = 1;
   	for(int i = 1; i <= n; i++){
   		for(auto v: adj[i]) if(colors[v] == colors[i]) { 
   			flag = 0;
   		}
   		sts[colors[i]].push_back(i);
   	}
   	if(!flag){
   		cout << "Alice" << endl;;
   		for(int j = 1; j <= n; j++){
   			cout << "1 2" << endl;
   			int a, b;
   			cin >> a >> b;
   			if(a == -1 || b == -1){
   				exit(0);
   			}
   		}
   	} else {
   		cout << "Bob" << endl;
   		for(int j = 1; j <= n; j++){
   			int a, b;
   			cin >> a >> b;
   			if(a == -1 || b == -1){
   				exit(0);
   			} if(b < a)
   				swap(a, b);	
   			if((a == 1 || b == 1) && !sts[0].empty()){
   				cout << sts[0].back() << " " << 1 << endl;
   				sts[0].pop_back();
   			} 
   			else if((a == 2 || b == 2) && !sts[1].empty()){
   				cout << sts[1].back() << " " << 2 << endl;
   				sts[1].pop_back();
   			} else {
   				if(!sts[0].empty()){
   					cout << sts[0].back() << " " << 3 << endl;
   					sts[0].pop_back();
   				} else {
   					cout << sts[1].back() << " " << 3 << endl;
   					sts[1].pop_back();
   				}
   			}
   		}
   	}	
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