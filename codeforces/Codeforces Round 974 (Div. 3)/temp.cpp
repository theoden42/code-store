#include <bits/stdc++.h>
#include <debug.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() 
{
    int n, m, h; cin >> n >> m >> h;
    
    vector <bool> have(n + 1, false);
    while (h--){
        int x; cin >> x;
        
        have[x] = true;
    }
    
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    // vector <int> d(n + 1, vector<int>(2, INF));
    // d[1][0] = 0;
    // if (have[1]){
    //     d[1][1] = 0;
    // }
    
    
    auto dij = [&](int s){
        vector <vector<int>> d(n + 1, vector<int>(2, INF));
        d[s][0] = 0;
        if (have[s]){
            d[s][1] = 0;
        }
        
        priority_queue <array<int, 3>> pq;
        pq.push({-d[s][0], s, 0});
        pq.push({-d[s][1], s, 1});
        
        while (!pq.empty()){
            auto pi = pq.top(); pq.pop();
            
            int u = pi[1];
            int t = pi[2];
            int ds = -pi[0];
            
            if (d[u][t] != ds){
                continue;
            }
            
            if (have[u]){
                t = 1;
            }
            
            for (auto [v, w] : adj[u]){
                int nd = ds;
                if (t) nd += w / 2;
                else nd += w;
                
                if (nd < d[v][t]){
                    d[v][t] = nd;
                    pq.push({-d[v][t], v, t});
                }
            }
        }
        
        vector <int> ans(n + 1);
        for (int i = 1; i <= n; i++){
            ans[i] = min(d[i][0], d[i][1]);
        }
        
        return ans;
    };
    
    auto d1 = dij(1);
    auto dn = dij(n);
    debug(d1, dn);
    
    int ans = INF;
    for (int s = 1; s <= n; s++){
        ans = min(ans, max(d1[s], dn[s]));
    }
    
    if (ans == INF){
        cout << -1 << "\n";
    } else {
        cout << ans << "\n";
    }
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}