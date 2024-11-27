

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int,vector<int>> mp;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i] % k].push_back(a[i]);
    }
    int fin = 0;
    int flag = 1;
    for(auto [_, v]: mp){
    	if(v.size() & 1 && !flag){
    		cout << "-1\n";
    		return;
    	} else if(v.size() & 1){
    		flag = 0;
    		sort(all(v));
    		int sz = v.size();
    		vector<int> odd(sz + 1), even(sz + 1);
    		for(int i = 1; i <= sz; i++){
    			odd[i] = odd[i - 1];
    			even[i] = even[i - 1];
    			if(i & 1){
    				odd[i] += v[i - 1];
    			} else {
    				even[i] += v[i - 1];
    			}
    		}
    		// debug(odd, even, v);
    		int mn = 1e18;
    		for(int i = 0; i < sz; i++){
    			int v = even[i] - odd[i];
    			v += (odd[sz] - odd[i + 1]) - (even[sz] - even[i + 1]);
    			mn = min(mn, v);
    		}
    		// debug(mn);
    		fin += mn / k;
    	} else {
    		int ans = 0;
	    	sort(all(v));
	    	// debug(v);
	    	for(int i = 0; i < v.size() - 1; i += 2){
	    		ans += (v[i + 1] - v[i]) / k;
	    	}
	    	fin += ans;
    	}

    }
    cout << fin << "\n";
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