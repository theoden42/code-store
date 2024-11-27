
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
    for(int i = 0; i < m; i++) { 
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    vector<int> dis(n + 1, 1e18);
    vector<int> vis(n + 1);
    vector<int> num(n + 1);
    vector<int> minf(n + 1, 1e9);
    vector<int> maxf(n + 1);

    multiset<pair<int,int>> mst;
    dis[1] = 0;
    num[1] = 1;
    minf[1] = 0;
    mst.insert({0, 1});

    for(int i = 2; i <= n; i++){
        mst.insert({dis[i], i});
    }

    while(!mst.empty()){
        auto [d, v] = *mst.begin();
        vis[v] = 1; 
        debug(v);
        mst.erase(mst.begin());
        for(auto [node, w]: adj[v]){
            if(vis[node])
                continue;
            int ndis = w + d;
            if(ndis < dis[node]){
                mst.erase(mst.find({dis[node], node}));
                num[node] = num[v];
                dis[node] = ndis;
                minf[node] = minf[v] + 1;
                maxf[node] = maxf[v] + 1;
                mst.insert({dis[node], node});
            } else if(ndis == dis[node]){
                debug(node, v);
                num[node] += num[v];
                num[node] %= MOD;
                minf[node] = min(minf[node], minf[v] + 1);
                maxf[node] = max(maxf[node], maxf[v] + 1);
            }
        }
        debug(num, maxf);
    }
    debug(dis, num, maxf);
    cout << dis[n] << " " << num[n] << " " << minf[n] << " " << maxf[n] << "\n";


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
