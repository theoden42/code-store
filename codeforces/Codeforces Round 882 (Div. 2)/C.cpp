

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


int get(int ind, int prv, vector<vector<int>>& dp, vector<int>& a){
	int n = dp.size();
	if(ind >= n)return prv;

	if(dp[ind][prv] != -1)
		return dp[ind][prv];

	int xr = (prv ^ a[ind]);

	int a1 = get(ind + 1, prv, dp, a);
	int a2 = get(ind + 1, xr, dp, a);

	int mx = max(a1, a2);
	// debug(prv, xr, ind, mx);
	return dp[ind][prv] = mx;

}


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int ans = *max_element(all(a));

    vector<int> prefix(n + 1);
    vector<int> mp(1 << 9, 0);

    int mx = 0;
    mp[0] = 1;

    for(int i = 1; i <= n; i++){
    	prefix[i] = prefix[i - 1];
    	prefix[i] ^= a[i - 1];

    	mp[prefix[i]]++;

    	int t = 0;

    	for(int j = (1 << 8) - 1; j >= 0; j--){
    		int fn = (prefix[i] ^ j);
    		if(mp[fn] >= 1){
    			t = j;
    			break;
    		}
    	}

    	mx = max(mx, t);
    }

    cout << max(ans, mx) << "\n";

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