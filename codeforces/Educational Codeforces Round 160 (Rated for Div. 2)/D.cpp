

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

#define int long long
const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
	vector<int> prefix(n + 1, 0), dp(n + 1, 0);
	stack<pair<int,int>> st;
	int stsum = 1;
	prefix[1] = 1;
	dp[1] = 1;
	st.push({a[1], 1});
    for(int i = 2; i <= n; i++){
    	while(!st.empty() && st.top().first > a[i]){
    		stsum -= dp[st.top().second];
    		stsum += MOD;
    		stsum %= MOD;
    		st.pop();
    	}
    	int ind = (st.empty()) ? 0: st.top().second;
    	int val = (prefix[i - 1] - prefix[ind] + MOD) % MOD;
    	val += stsum;
    	val %= MOD;
    	if(ind == 0){
    		val += 1;
    		val %= MOD;
    	}
    	dp[i] = val;
    	st.push({a[i], i});
    	stsum += dp[i];
    	stsum %= MOD;
    	prefix[i] += prefix[i - 1];
    	prefix[i] += dp[i];
    	prefix[i] %= MOD;
	}

    int mn = 1e9 + 5;
    int ans = 0;
    for(int i = n; i >= 1; i--){
    	if(a[i] < mn){
    		ans += dp[i];
    		ans %= MOD;
    		mn = a[i];
    	}
    }
    cout << ans << "\n";
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