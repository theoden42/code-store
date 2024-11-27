

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]] += 1;
    }

    int mx = 0;
    for(int i = 0; i <= n; i++){
    	if(mp[i] == 0){
    		mx = i;
    		break;
    	}
    }

    vector<int> dp(mx + 1);
    vector<int> freq(mx + 1);
    for(int i = 0; i <= mx; i++){
    	freq[i] = mp[i];
    }

    dp[0] = 0;
    for(int i = 1; i <= mx; i++){
    	int mn = 1e18;
    	for(int j = 0; j < i; j++){
    		int value = j + i * (freq[j] - 1) + dp[j];
    		mn = min(mn, value);
    	}
    	dp[i] = mn;
    }

    cout << dp[mx] << "\n";

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