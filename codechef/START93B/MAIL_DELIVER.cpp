

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), d(k);

    vector<vector<int>> adj(n + 1);

    vector<pair<int,int>> temp(k);
    for(int i = 0; i < k; i++){
    	cin >> temp[i].second;
    }
    for(int i = 0; i < k; i++){
    	cin >> temp[i].first;
    }

    sort(temp.rbegin(), temp.rend());

    for(int i = 0; i < k; i++){
    	x[i] = temp[i].second;
    }
    for(int i = 0; i < k; i++){
    	d[i] = temp[i].first;
    }



    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }



    vector<int> dis(n + 1, INF);
  	vector<int> vis(n + 1);

  	for(int i = 0; i < k; i++){

  		queue<int> q;
  		dis[x[i]] = 1;
  		vis[x[i]] = 1;
  		q.push(x[i]);

  		while(!q.empty()){
  			int u = q.front();
  			q.pop();
  			if(dis[u] >= d[i]) break;

  			for(auto x: adj[u]){
  				if(dis[x] < dis[u] + 1)continue;
  				else{
					vis[x] = 1;
					dis[x] = dis[u] + 1;
					q.push(x);	
  				}
  			}

  		}
  	}

  	debug(vis);


  	for(int i = 1; i <= n; i++){
  		if(!vis[i]){
  			cout << "NO\n";
  			return;
  		}
  	}

  	cout << "YES\n";

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