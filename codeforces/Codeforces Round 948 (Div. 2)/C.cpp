

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
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    sort(all(a));
    int f = 1;
    for(int i = 0; i < n - 1; i++){
    	if(a[n - 1] % a[i] != 0){
    		f = 0;
    		break;
    	}
    }
    if(!f){
    	cout << n << "\n";
    	return;
    }
    map<int,int> mp;
    map<int,int> mp2;
    int count = 0;
    for(int i = 1; i * i <= a.back(); i++){
        if(a.back() % i == 0){
            mp[i] = count++;
            mp2[mp[i]] = i;
            if(a.back() / i != i){
                mp[a.back() / i] = count++;
                mp2[mp[a.back() / i]] = a.back() / i;
            }
        }
    }
    vector<int> dp(count), ndp(count);
    const int mx = count;
    for(int i = 0; i < n; i++){
    	for(int k = 0; k < mx; ++k){
            int j = mp2[k];
    		ndp[k] = max(ndp[k], dp[k]);
            ndp[mp[a[i]]] = max(ndp[mp[a[i]]], 1ll);
            if(dp[k] == 0)
                continue;
    		int lcm = (j * a[i]) / __gcd(j, a[i]);
            int ind = mp[lcm];
    		ndp[ind] = max(ndp[ind], dp[k] + 1);
    	}
    	dp.assign(all(ndp));
    	ndp.assign(mx, 0);
    }
    set<int> st;
    for(auto x: a){
    	st.insert(x);
    }
    int ans = 0;
    for(auto [key, val]: mp){
        if(st.find(key) == st.end())
            ans = max(ans, dp[val]);
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