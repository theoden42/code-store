/* @uthor: (g)theoden42 */
 
#include <bits/stdc++.h>
using namespace std;
 
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif
 
#define ll long long
#define ld long double
#define int long long
#define all(a) (a).begin(), (a).end()
 
const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> vis(n + 1), curr(n + 1);
    vector<int> path;
    function<int(int)> dfs = [&](int source){
        vis[source] = 1;
        path.push_back(source);
        curr[source] = 1;

        for(auto node: adj[source]){
            if(curr[node]){
                path.push_back(node);
                return 1;
            }
            if(!vis[node]){
                if(dfs(node)) 
                    return 1;
            }
        }

        path.pop_back();
        curr[source] = 0;
        return 0;
    };

    for(int i = 1; i <= n; i++){
        if(!vis[i] && dfs(i)){
            debug(path);
            vector<int> finalpath;
            auto last = path.back();
            finalpath.push_back(last);
            path.pop_back();
            while(finalpath.back() != last || finalpath.size() < 2){
                finalpath.push_back(path.back());
                path.pop_back();
            }
            reverse(all(finalpath));
            cout << finalpath.size() << "\n";
            for(auto p: finalpath){
                cout << p << " ";
            }
            cout << "\n";
            return;
        }
    }

    cout << "IMPOSSIBLE\n";

}
 
int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
