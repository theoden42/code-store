

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

vector<vector<int>> adj;
vector<int> vis;

int dfs(int source, int parent, int start){
	// debug(source);
	vis[source] = 1;
	int x = 0;
	for(auto x: adj[source]){
		if(x == start && start != parent)return true;

		if(!vis[x]){
			if(dfs(x, source, start))return true;
		}
	}

	return x;
}


void solve() {
    int n, m;
    cin >> n >> m;
    adj.clear();
    vis.clear();
    adj.resize(n);
    vis.resize(n);

    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> cycles;

   	for(int i = 0; i < n; i++){
   		vis.assign(n, 0);
   		if(dfs(i, -1, i)){
   			cycles.push_back(i);
   		}
   	}


   	int ans = -1;
   	for(auto x: cycles){
   		if(adj[x].size() >= 4){
   			ans = x;
   			break;
   		}
   	}

   	vector<int> vrtx;
	function<int(int,int,int)> dfs2 = [&](int source, int parent, int start)->int{
   		vis[source] = 1;

   		for(auto x: adj[source]){
   			if(x == start && x != parent){
   				vrtx.push_back(source);
   				vrtx.push_back(start);
   				return true;
   			}
   		}

   		for(auto x: adj[source]){
   			if(!vis[x]){
   				vrtx.push_back(source);
 				if(dfs2(x, source, start)){
 					return true;
 				}
 				vrtx.pop_back();
   			}
   		}
   		return false;
   	};

   	if(ans == -1){
   		cout << "NO\n";
   		return;
   	}
   	else{
   		cout << "YES\n";
   		vis.assign(n, 0);
		dfs2(ans, -1, ans);
		vector<int> others;

		for(auto x: adj[ans]){
			if(find(all(vrtx), x) == vrtx.end()){
				others.push_back(x);
			}
		}

		cout << vrtx.size() + 1 << "\n";

		for(int i = 0; i < vrtx.size() - 1; i++){
			cout << vrtx[i] + 1 << " " << vrtx[i + 1] + 1 << "\n";
		}
		for(int i = 0; i < 2 && i < others.size(); i++){
			cout << ans + 1 << " " << others[i] + 1 << "\n";
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