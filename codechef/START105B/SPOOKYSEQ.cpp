

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

vector<int> f(MAX_N);

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
 

void precompute(){
	f[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		f[i] = (f[i - 1] * i) % MOD;
	}
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i = 0; i < m; i++){
    	int u, v;
    	cin >> u >> v;
    	u--;
    	v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<int> vis(n);
    function<void(int, int&, map<int,int>&)> dfs = 
    [&](int source, int& count, map<int,int>& mp) { 
    	vis[source] = 1;
    	count += 1;
    	mp[a[source]] += 1;
    	for(auto x: adj[source]){
    		if(!vis[x]){
    			dfs(x, count, mp);
    		}
    	}
    };

    int ans = 1;
    vector<int> comp_size;
    for(int i = 0; i < n; i++){
    	if(vis[i])
    		continue;
    	int count = 0;
    	map<int,int> mp;
    	dfs(i, count, mp);
    	int value = 1;
    	for(auto it: mp){
    		value *= f[it.second];
    		value %= MOD;
    	}
    	ans *= value;
    	ans %= MOD;
    	comp_size.push_back(count);
    }


    ans *= f[n];
    ans %= MOD;
    for(auto sz: comp_size){
    	ans *= modinverse(f[sz]);
    	ans %= MOD;
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    precompute();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}