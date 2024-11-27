
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
    vector<int> indeg(n + 1);
    vector<int> depth(n + 1);
    vector<int> parent(n + 1);
    
    for(int i = 2; i <= n; i++){
        int p;
        cin >> p;
        adj[p].push_back(i);
        parent[i] = p; 
        indeg[p] += 1;
    }
    function<void(int,int,int)> dfs = [&](int source, int parent, int level){
        depth[source] = level;
        for(auto x: adj[source]){
            if(x == parent)
                continue;
            dfs(x, source, level + 1);
        }
    }; dfs(1, -1, 0);

    multiset<pair<int,int>> mst;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0)
            mst.insert({-depth[i], i});
    }
    int ans = 0;
    while(mst.size() > 1){
        auto [val, ind] = *(mst.begin());
        mst.erase(mst.begin());
        auto [val2, ind2] = *mst.begin();
        mst.erase(mst.begin());
        auto p1 = parent[ind];
        auto p2 = parent[ind2];
        ans += 1;
        indeg[p1] -= 1;
        if(indeg[p1] == 0){
            mst.insert({-depth[p1], p1});
        } 
        indeg[p2] -= 1;
        if(indeg[p2] == 0){
            mst.insert({-depth[p2], p2});
        }
    }
    cout << ans << "\n";
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
