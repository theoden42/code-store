

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
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vector<int> nloc(n + 1);
    nloc[0] = 0;
    for(int i = 1; i <= n; i++){
        nloc[i] = i + b[i];
    }

    vector<int> dis(n + 1, INF);
    vector<int> vis(n + 1);
    vector<int> parent(n + 1);
    vector<int> slip(n + 1);
    int lst = n;
    queue<int> q;
    q.push(n);
    dis[n] = 0; 
    vis[n] = 1;
    while(!q.empty()){
        auto nd = q.front();
        q.pop();
        int left = max(0, nd - a[nd]);
        for(int j = lst - 1; j >= left; j--){
            int dest = nloc[j];
            if(!vis[dest]){
                slip[dest] = j;
                parent[j] = nd;
                vis[dest] = 1;
                dis[dest] = dis[nd] + 1;
                q.push(dest);
            }
        }
        lst = min(left, lst);
    }

    // debug(dis, parent, slip);

    if(dis[0] == INF){
        cout << "-1\n";
        return;
    }
    cout << dis[0]   << "\n";
    int p = 0;
    vector<int> path;
    while(p != n){
        p = slip[p];
        path.push_back(p);
        p = parent[p];
    }
    reverse(all(path));
    for(auto p: path){
        cout << p << " ";
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