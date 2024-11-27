

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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;

}


vector<vector<int>> adj;
vector<int> subtree;
vector<int> vis;

int dfs(int source){
    vis[source] = 1;
    int count = 1;
    for(auto x: adj[source]){ 
        if(vis[x])continue;
        count += dfs(x);
    }
    subtree[source] = count;
    return subtree[source];
}

void dfs2(int source, int& ans){
    int n = adj.size();
    vis[source] = 1;
    for(auto x: adj[source]){
        if(!vis[x]){
            ans += (1ll * subtree[x] * (n - subtree[x])) % MOD;
            ans %= MOD;
            dfs2(x, ans);
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    adj.resize(n);
    subtree.resize(n);
    vis.resize(n);
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k == 1 || k == 3){
    	cout << 1 << "\n";
    }else{
        dfs(0);
        vis.assign(n, 0);
        int ans = 0;
        dfs2(0, ans); 
        int div = (n * (n - 1)) % MOD;
        ans = (ans * 2) % MOD;
        ans = (ans * modinverse(div) + 1) % MOD;
        cout << ans << "\n";
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}