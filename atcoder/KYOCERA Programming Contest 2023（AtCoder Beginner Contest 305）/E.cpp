

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(k), d(k);

    vector<vector<int>> adj(n + 1);


    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<pair<int,int>> temp(k);
    for(int i = 0; i < k; i++){
    	cin >> temp[i].second >> temp[i].first;
    }
    // for(int i = 0; i < k; i++){
    // 	cin >> temp[i].first;
    // }

    // sort(temp.rbegin(), temp.rend());

    for(int i = 0; i < k; i++){
    	x[i] = temp[i].second;
    }
    for(int i = 0; i < k; i++){
    	d[i] = temp[i].first;
    }

    vector<int> dis(n + 1, INF);
  	vector<int> vis(n + 1);

    priority_queue<pair<int,int>> q;
    for(int i = 0; i < k; i++){
        q.push({d[i], x[i]});
    }

    while(!q.empty()){

        auto it = q.top();
        q.pop();
        vis[it.second] = 1;

        if(it.first == 0)continue;

        for(auto x: adj[it.second]){
            if(!vis[x]){

                dis[x] = it.first - 1;
                vis[x] = 1;
                q.push({dis[x], x});
            }
        }
    }

    vector<int> ans;
  	for(int i = 1; i <= n; i++){
  		if(vis[i]){
            ans.push_back(i);
  		}
  	}

    cout << ans.size() << "\n";
    for(auto x: ans){
        cout << x << " ";
    }
    cout << "\n";

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