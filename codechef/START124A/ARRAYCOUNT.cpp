

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

ll modinverse(ll a, ll b=MOD){
    return binpow(a, b - 2) % MOD;
}


void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> f;
    for(int i = 1; i * i <= x; i++){
    	if(x % i == 0){
    		f.push_back(i);
    		if(x / i != i)
    			f.push_back(x / i);
    	}
    }

    vector<pair<int,int>> vp;
    int temp = x;
    for(int i = 2; i * i <= x; i++){
    	int count = 0;
    	while(temp % i == 0){
    		count += 1;
    		temp /= i;
    	}
    	if(count == 0)
    		continue;

    	vp.push_back({i, count});
    }

    if(temp != 1){
    	vp.push_back({temp, 1});
    }

    vector<vector<int>> nc(f.size());
    for(int i = 0; i < nc.size(); i++){
    	int ind = 0;
    	for(auto [p, c]: vp){
    		int count = 0;
            int temp = f[i];
    		while(temp % p == 0){
    			count += 1;
                temp /= p;
            }

    		if(count == c)
    			nc[i].push_back(ind);
    		ind += 1;
    	}
    }

    int sz = vp.size();

    int ans = 0;

    for(int i = 0; i < (1 << sz) - 1; i++){
    	int count = 0;
    	for(int j = 0; j < nc.size(); j++){
    		int f = 1;
    		for(int k = 0; k < nc[j].size(); k++){
    			if(!((i >> nc[j][k]) & 1)){
    				f = 0;
    				break;
    			}
    		}
    		if(f)
    			count += 1;
    	}

    	int total = (count == 1 ? n : ((((binpow(count, n + 1) - 1 + MOD) % MOD) * modinverse(count - 1)) % MOD - 1 + MOD) % MOD);
    	total += MOD;
    	total %= MOD;

        int zcount = 0;
        for(int j = sz - 1; j >= 0; j--){
            if(!(i >> j & 1)){
                zcount += 1;
            }
        }
        debug(i, count);
        if(zcount & 1){
            ans += total;
            ans %= MOD;
        } else {
            ans -= total;
            ans += MOD;
            ans %= MOD;
        }
    }


    int finalans = (f.size() == 1 ? n : ((((binpow(f.size(), n + 1) - 1 + MOD) % MOD) * modinverse(f.size() - 1)) % MOD - 1 + MOD) % MOD);
    finalans += MOD;
    finalans %= MOD;

    finalans -= ans;
    finalans += MOD;

    finalans %= MOD;

    cout << finalans << "\n";

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