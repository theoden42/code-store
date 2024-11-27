

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
    vector<vector<int>> adj(n + 1), rev(n + 1);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	if(v < u)
    		swap(u, v);
    	adj[u].push_back(v);
        rev[v].push_back(u);
    }	
    for(int i = 1; i <= n - 1; i++){
    	adj[i].push_back(i + 1);
        rev[i + 1].push_back(i);
    }

    multiset<pair<int,int>> dist;
    cout << 1;
    vector<int> dp(n + 1);
    for(int i = 1; i <= n; i++){
        dp[i] = i - 1;
        dist.insert({i - dp[i], i});
    }
    for(int i = 1; i < n - 1; i++){
        // debug(dist);
        dist.erase({i - dp[i], i});
        for(auto x: adj[i]){
            dist.erase({x - dp[x], x});
            dp[x] = min(dp[x], dp[i] + 1);
            dist.insert({x - dp[x], x});
        }
        // debug(dp);
        auto [v, _] = *prev(dist.end(), 1);
        if(v <= i + 1){
            cout << "1";
        } else {
            cout << "0";
        }
    }
    cout << "\n";
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