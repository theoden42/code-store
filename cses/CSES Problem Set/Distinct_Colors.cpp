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
    vector<int> cols(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> cols[i];
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    vector<int> dst(n + 1);
    function<unordered_set<int>(int,int)> dfs
    = [&](int src, int parent) { 
        unordered_set<int> tmp;
        tmp.insert(cols[src]);
        for(auto x: adj[src]) if( x != parent) { 
            unordered_set<int> nwtmp = dfs(x, src);
            if(nwtmp.size() < tmp.size()){
                tmp.insert(all(nwtmp));
            } else {2w
                nwtmp.insert(all(tmp));
                tmp = move(nwtmp);
            }
        }
        dst[src] = tmp.size();
        return tmp;
    }; 
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        cout << dst[i] << " \n"[i == n];
    }
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