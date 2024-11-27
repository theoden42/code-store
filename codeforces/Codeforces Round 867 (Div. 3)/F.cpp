

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

void dfs(int source, int parent, int d, vector<vector<int>>& adj, vector<int>& dis){
	dis[source] = d;

	for(auto x: adj[source]){
		if(x != parent){
			dfs(x, source, d + 1, adj, dis);
		}
	}
}


void solve() {
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> dis(n, 0);
    dfs(0, -1, 0, adj, dis);

	int mx = 0;
	int v = 0;
	for(int i = 0; i < n; i++){
		if(dis[i] >= mx){
			mx = dis[i];
			v = i;
		}
	}

	vector<int> dis2(n);
	dfs(v, -1, 0, adj, dis2);

	mx = 0;
	int v2 = 0;
	for(int i = 0; i < n; i++){
		if(dis2[i] >= mx){
			mx = dis2[i];
			v2 = i;
		}
	}


	vector<int> dis3(n);
	dfs(v2, -1, 0, adj, dis3);


	int mn = 0;
	for(int i = 0; i < n; i++){
		int temp = max(dis3[i], dis2[i]) * k - c * dis[i];
		mn = max(mn, temp);
	}

	cout << mn << "\n";
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