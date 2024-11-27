

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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> vp(m);
    for(int i = 0; i < m; i++){
    	cin >> vp[i].first >> vp[i].second;
    	vp[i].first--;
    	vp[i].second--;
    }
    vector<int> dp(n, 1);
    int curr = 0;
    for(int i = 1; i <= k; i++){
    	map<int,int> mp;
    	for(auto [a, b]: vp){
    		int shif_a = (a + curr + 1) % n;
    		int unshif_b = (b + curr) % n;	
    		if(mp.find(shif_a) == mp.end()){
    			mp[shif_a] = dp[shif_a];
    		}
    		mp[shif_a] += dp[unshif_b];
    		mp[shif_a] %= MOD;
    	}
    	for(auto& [k, v]: mp){
    		dp[k] = v;
    	}
    	curr += 1;
    }

    int ans = dp[k % n];
    cout << ans << "\n";
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