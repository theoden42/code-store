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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    map<int,int> mp;
    for(int i = 0; i < k; i++){
    	cin >> a[i];
    	a[i]--;
    	mp[a[i]] = 1;
    }
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;	
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> dis(n);
    vector<int> dis2(n);
    function<void(int,int,int)> dfs = [&](int source, int parent, int d){
        dis[source] = d;
        for(auto node: adj[source]){
            if(node == parent)
                continue;
            dfs(node, source, d + 1);
        }
    };
    function<void(int,int,int)> dfs2 = [&](int source, int parent, int d){
        dis2[source] = d;
        for(auto node: adj[source]){
            if(node == parent)
                continue;
            dfs2(node, source, d + 1);
        }
    };
    dfs(0, -1, 0);
    // debug(dis);
    int node = 0;
    int dist = 0;
    for(int i = 0; i < n; i++){
        if(mp[i]){
            if(dis[i] >= dist){
                dist = dis[i];
                node = i;
            }
        }
    }
    dfs2(node, -1, 0);
    // debug(dis2); 
    int node2 = 0;
    int dist2 = 0;
    for(int i = 0; i < n; i++){
        if(mp[i]){
            if(dis2[i] >= dist2){
                dist2 = dis2[i];
                node2 = i;
            }
        }
    }

    // debug(node, node2);

    dfs(node, -1, 0);
    dfs2(node2, -1, 0);
    int ans = 1e9;
    for(int i = 0; i < n; i++){
        ans = min(ans, max(dis[i], dis2[i]));
    }
    cout << ans << "\n";

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