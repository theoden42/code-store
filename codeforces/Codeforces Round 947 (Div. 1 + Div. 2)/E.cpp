

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
    int n, q;
    cin >> n >> q;
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> parent(n + 1);
    vector<multiset<int>> childs(n + 1);
    set<int> twochilds;
    int ends = 0;
    function<void(int,int)> dfs = [&](int source, int pnt=-1){
        parent[source] = pnt;
        for(auto x: adj[source]) if (x != pnt){
            dfs(x, source);
        }
    }; dfs(1, -1);

    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(c[i]){
            if(parent[i] == -1){
                ends += 1;
            } else if(c[parent[i]] == 0){
                ends += 1;
                childs[parent[i]].insert(i);
            } else {
                childs[parent[i]].insert(i);
                if(childs[parent[i]].size() >= 2){
                    twochilds.insert(parent[i]);
                }
            }
        }
    }

    auto check = [&](){
        if(ends != 1){
            cout << "No\n";
            return;
        }
        if(twochilds.size() > 1){
            cout << "No\n";
            return;
        }
        if(twochilds.empty() || ((parent[*twochilds.begin()] == -1 || c[parent[*twochilds.begin()]] == 0) && childs[*twochilds.begin()].size() <= 2)){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    };
    for(int i = 1; i <= q; i++){
        int u;
        cin >> u;
        c[u] = 1 - c[u];
        if(!c[u]){ // white
            ends += childs[u].size();
            if(twochilds.find(u) != twochilds.end()){
                twochilds.erase(u);
            }
            if(parent[u] == -1 || c[parent[u]] == 0)
                ends -= 1;
            if(parent[u] != -1){
                childs[parent[u]].erase(u);
                if(twochilds.find(parent[u]) != twochilds.end()){
                    twochilds.erase(parent[u]);
                }
                if(childs[parent[u]].size() > 1 && c[parent[u]]){
                    twochilds.insert(parent[u]);
                }
            }
        } else {
            // debug(childs[u], parent[u]);
            ends -= childs[u].size();
            if(childs[u].size() > 1){
                twochilds.insert(u);
            }
            // debug(twochilds);
            if(parent[u] == -1){
                ends += 1;
            } else if(c[parent[u]] == 0){
                ends += 1;
                childs[parent[u]].insert(u);
            }
            else {
                childs[parent[u]].insert(u);
                // debug(twochilds);
                if(childs[parent[u]].size() >= 2){
                    twochilds.insert(parent[u]);
                }
                // debug(twochilds);
            }
        }
        // debug(ends, twochilds, childs);
        check();
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