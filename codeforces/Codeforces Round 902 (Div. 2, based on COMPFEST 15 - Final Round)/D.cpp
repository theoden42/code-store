

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	vp[i] = {a[i], i + 1};
    }
    sort(vp.rbegin(), vp.rend());

    int ans = 0;
    int available = n;
    vector<int> vis(n + 1);

    for(int i = 0; i < n; i++) { 
    	if(vis[vp[i].second])
    		continue;
        // debug(vp[i]);
    	int ind = vp[i].second;	
    	vector<int> factors;	
    	for(int j = 1; j * j <= ind; j++){
    		if(ind % j != 0)
    			continue;
    		int f1 = j;
    		int f2 = ind / j;
            if(f1 == f2) { 
                if(!vis[f1]) { 
                    factors.push_back(f1);
                    continue;
                }
            }
    		if(!vis[f1])
    			factors.push_back(f1);
    		if(!vis[f2])
    			factors.push_back(f2);
    	}

    	int sz = factors.size();
    	int total = binpow(2, sz) - 1;
    	total += MOD;
    	total %= MOD;
    	int temp = binpow(2, available - sz);
    	total *= temp;
    	total %= MOD;
    	temp = (vp[i].first * total) % MOD;
    	ans += temp;
    	ans %= MOD;
    	for(auto f: factors) { 
    		vis[f] = 1;
    	}
    	available -= sz;
    }


    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}