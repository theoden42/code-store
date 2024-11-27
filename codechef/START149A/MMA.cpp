

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
    int n, x, k;
    cin >> n >> x >> k;
    vector<int> v(n);
    ordset<int> st, single;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    	st.insert(v[i]);
    	mp[v[i]] += 1;
    }
    for(auto [k, v]: mp){
    	if(v == 1){
    		single.insert(k);
    	}
    }
    sort(all(v));	
    int mx = x * k;
    int del = st.order_of_key(mx);
    for(int i = n - 1; i >= 0; i--){
    	if(v[i] < x){
    		int right = st.order_of_key(x);
    		int left = st.order_of_key(v[i]);
    		int temp = right - left;
    		int nw = v[i] * k;
    		temp += st.order_of_key(nw);
    		int rep = single.order_of_key(min(x, nw)) - single.order_of_key(v[i]);
    		temp -= rep;
    		del = max(del, temp);
    	}
    }
    cout << del << "\n";
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