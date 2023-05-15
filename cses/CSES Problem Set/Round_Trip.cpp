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
 
int dfs(int source, int parent, vector<int>& vis, vector<vector<int>>& g, vector<int>& vertex){
    debug(source);
    vis[source] = 1;
    vertex.push_back(source);
 
    for(auto& x: g[source]){
        if(vis[x] && x != parent){
            vertex.push_back(x);
            return true;
        }
    }
    for(auto& x: g[source]){
        if(!vis[x]){
            if(dfs(x, source, vis, g, vertex)){
                return true;
            }
        }
    }
    vertex.pop_back();
    return false;
}
 
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; ++i){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    vector<int> vertex;
    vector<int> vis(n, 0);
 
    for(int i = 0; i < n; i++){
        if(!vis[i]){    
            vertex.clear();
            if(dfs(i, -1, vis, g, vertex)){
 
                int lv = vertex[(int)vertex.size() - 1];
                int i = (int)vertex.size() - 2;
                vector<int> ans;
                ans.push_back(lv);
                while(vertex[i] != lv){
                    ans.push_back(vertex[i]);
                    i--;
                }
                ans.push_back(lv);
 
                cout << ans.size() << "\n";
                for(auto& x: ans){
                    cout << x + 1 << " ";
                }
                return;
            }
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
