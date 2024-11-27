

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
    vector<vector<int>> prefix(n + 1, vector<int>(31, 0));
    for(int i = 1; i <= n; i++){
    	int temp = a[i - 1];
    	for(int j = 0; j < 31; j++){
    		prefix[i][j] = prefix[i - 1][j];
    		if(temp & 1ll){
    			prefix[i][j] += 1;
    		}
    		temp >>= 1ll;
    	}
    }

    vector<int> oddind(31, 0);
    vector<int> evenind(31, 0);
    vector<int> codd(31, 0);
    vector<int> ceven(31, 0);
    int sum = 0;
    for(int j = 0; j < 31; j++){
        ceven[j] += 1;
    }

    for(int i = 1; i <= n; i++){
    	for(int j = 0; j < 31; j++){
    		int val = binpow(2, j);
    		if(prefix[i][j] & 1){
                int len = (((ceven[j] * i) % MOD - evenind[j]) % MOD + MOD) % MOD;
                len %= MOD;
                val *= len;
                val %= MOD;
                sum += val;
                sum %= MOD;
    		} else if(prefix[i][j] > 0){
    			int len = (((codd[j] * i) % MOD - oddind[j]) % MOD + MOD) % MOD;
                len %= MOD;
    			val *= len;
    			val %= MOD;
    			sum += val;
    			sum %= MOD;
    		}
    		if(prefix[i][j] & 1){
    			codd[j] += 1;
                codd[j] %= MOD;
    			oddind[j] += i;
                oddind[j] %= MOD;
    		} else {
    			ceven[j] += 1;
                ceven[j] %= MOD;
    			evenind[j] += i;
                evenind[j] %= MOD;
    		} 
    	}
    }

    cout << sum << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}