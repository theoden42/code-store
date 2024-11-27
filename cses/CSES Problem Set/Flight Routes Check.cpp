
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
    vector<vector<int>> adjt(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }

    vector<int> order;
    vector<int> vis(n + 1);
    function<void(int)> dfs = [&](int source) { 
        vis[source] = 1;
        for(auto x: adj[source]) 
            if(!vis[x]) 
                dfs(x);
        order.push_back(source);
    };
    for(int i = 1; i <= n; i++){ 
        if(!vis[i])
            dfs(i);
    }
    reverse(all(order));
    vector<int> components;
    vis.assign(n + 1, 0);

    function<void(int)> dfs2 = [&](int source){ 
        vis[source] = 1;
        components.push_back(source);
        for(auto x: adjt[source]) 
            if(!vis[x]){
                dfs2(x);
            }
    };
    vector<int> roots;
    debug(roots);
    for(auto i: order){ 
        if(!vis[i]){
            dfs2(i);
            roots.push_back(components.front()); 
            components.clear();
        }
    }

    if(roots.size() >= 2){
        cout << "NO\n";
        cout << roots[1] << " " << roots[0] << "\n";
    } else {
        cout << "YES\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
//    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
