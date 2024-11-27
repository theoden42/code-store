

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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> sz(n + 1);
    function<int(int,int)> findsz
    = [&](int source, int parent){
    	int x = 1;
    	for(auto nd: adj[source])if(nd != parent){
    		x += findsz(nd, source);
    	}
    	return sz[source] = x;
    };findsz(1, -1);

   	int centroid = -1;
   	function<void(int,int)> findcent
   	= [&](int source, int parent){
   		int sum = n - sz[source];
   		int f = 1;
   		for(auto nd: adj[source])if(nd != parent){
   			if(sz[nd] > n / 2)
   				f = 0;
   		}
   		for(auto nd: adj[source]) if (nd != parent) { 
   			findcent(nd, source);
   		}
   		if(f && sum <= n / 2){
   			centroid = source;
   		}
   	}; findcent(1, -1);

   	cout << centroid << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}