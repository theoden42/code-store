

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
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vector<int> c(n + 1);
    for(int i = 1; i <= n; i++){
    	int x;
    	cin >> x;
    	adj[i].push_back(x);
    }
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }

    vector<int> vis(n + 1);
    vector<int> currvis(n + 1);
    vector<int> elements;

    function<void(int, vector<int>&)> dfs 
    = [&](int source, vector<int>& cycle){
        vis[source] = 1;
        currvis[source] = 1;
        elements.push_back(source);
        for(auto x: adj[source]){
            if(currvis[x]){
                for(int i = elements.size() - 1; i >= 0; i--){
                    cycle.push_back(elements[i]);
                    if(elements[i] == x){
                        break;
                    }
                }   
            }   
            if(!vis[x]){
                dfs(x, cycle);
            } 
        }
        elements.pop_back();
        currvis[source] = 0;
    };


    for(int i = 1; i <= n; i++){
        if(vis[i])
            continue;
        vector<int> cycle;
        dfs(i, cycle);
        if(cycle.empty())
            continue;
        int mn = 1e9 + 5;
        int mnindex = 0;
        for(auto i: cycle){
            if(c[i] < mn){
                mn = c[i];
                mnindex = i;   
            }
        }
        adj[mnindex].clear();
    }

    // debug(adj);

    vector<int> topo_sort;

    vector<int> indeg(n + 1);
    for(int i = 1; i <= n; i++){
        for(auto it: adj[i]){
            indeg[it] += 1;
        }
    }
    // debug(indeg);

    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto f = q.front();
        q.pop();
        topo_sort.push_back(f);
        for(auto x: adj[f]){
            indeg[x] -= 1;
            if(indeg[x] == 0){
                q.push(x);
            }
        }
    }

    assert(topo_sort.size() == n);
    for(auto it: topo_sort){
        cout << it << " ";
    }
    cout << "\n";

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