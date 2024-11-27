

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
    vector<vector<pair<int,int>>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    }

    vector<int> vis1(n + 1), vis2(n + 1);
    vector<int> par(n + 1, -1);
    vector<int> dis1(n + 1, 1e15 + 7), dis2(n + 1, 1e15 + 7);

    multiset<pair<int,int>> mst;
    vis1[1] = 1; dis1[1] = 0;
    for(int i = 1; i <= n; i++){
    	mst.insert({dis1[i], i});
    }

    while(!mst.empty()){
    	auto [_, x] = *mst.begin();
    	vis1[x] = 1;
    	mst.erase(mst.begin());
    	for(auto [y, w]: adj[x]){
    		if(!vis1[y] && dis1[y] > dis1[x] + w){
    			mst.erase({dis1[y], y});
    			dis1[y] = dis1[x] + w;
    			par[y] = x;
    			mst.insert({dis1[y], y});
    		}
    	}
    }

    vis2[n] = 1;
    dis2[n] = 0;
    for(int i = 1; i <= n; i++){
    	mst.insert({dis2[i], i});
    }

    while(!mst.empty()){
    	auto [_, x] = *mst.begin();
    	vis2[x] = 1;
    	mst.erase(mst.begin());
    	for(auto [y, w]: adj[x]){
    		if(!vis2[y] && dis2[y] > dis2[x] + w){
    			mst.erase({dis2[y], y});
    			dis2[y] = dis2[x] + w;
    			mst.insert({dis2[y], y});
    		}
    	}
    }

    int mx1 = dis1[n];

    int ans = 1e15 + 7;
    int lst = -1;

    int nd = n;
    while(nd != -1){
        int val = mx1;
        for(auto [y, w]: adj[nd]){
            if(y == par[nd] || y == lst)
                continue;
            int dist = dis2[nd] + w + dis1[y];
            ans = min(ans, mx1 + dist);
        }

        lst = nd;
        nd = par[nd];
    }


    if(ans >= 1e15)
        ans = -1;

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}