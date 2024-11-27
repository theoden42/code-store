

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

#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> adj(n + 1);	

    for(int i = 1; i <= n - 1; i++){
    	int a, b, x;
    	cin >> a >> b >> x;
    	adj[i].push_back({i + 1, a});
    	adj[i].push_back({x, b});
    }

    vector<int> dis(n + 1, INF);
    vector<int> vis(n + 1);
    multiset<pair<int,int>> mst;
    dis[1] = 0;
    for(int i = 1; i <= n; i++){
    	mst.insert({dis[i], i});
    }

    while(!mst.empty()){
        // debug(mst);
    	auto [curr, node] = *mst.begin();
    	mst.erase(mst.begin());
    	vis[node] = 1;
    	for(auto [nw, w]: adj[node]){
    		if(!vis[nw] && dis[nw] > dis[node] + w){
    			mst.erase(mst.find({dis[nw], nw}));
    			dis[nw] = dis[node] + w;
    			mst.insert({dis[nw], nw});
    		}
    	}
    }


    cout << dis[n] << "\n";
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