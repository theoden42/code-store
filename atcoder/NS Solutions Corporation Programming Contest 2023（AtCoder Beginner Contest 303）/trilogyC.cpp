

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

#define int int64_t

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

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}

void solve() {
	int n;
	cin >> n;
	vector<int> dp(n + 1);
	dp[1] = 0;
	for(int i = 2; i <= n; i++){
		set<int> st;
		for(int j = 1; j * j <= i; j++){
			if(i % j == 0){
				st.insert(j);
				st.insert(i / j);	
			}
		}
		int prob = modinverse(st.size());
		int ans = prob;
		for(auto x: st){
			if(x == 1)
				continue;	

			int val = prob * (1 + dp[i / x]);
			val %= MOD;
			ans += val;
			ans %= MOD;
		}
		ans *= st.size();
		ans %= MOD;
		ans *= modinverse(st.size() - 1);
		ans %= MOD;		
		dp[i] = ans;
	}

	// debug(dp);

	int finalans = 0;
	for(int i = 1; i <= n; i++){
		finalans += dp[i];
		finalans %= MOD;		
	}
	finalans *= modinverse(n);	
	finalans %= MOD;
	cout << finalans << "\n";
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