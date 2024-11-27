

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

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    map<int,vector<int>> mp;
    vector<int> pref(n + 1);
    int p = 0;
    mp[0].push_back(0);
    for(int i = 0; i < n; i++){
    	p ^= a[i];
    	pref[i + 1] = p;
    	mp[p].push_back(i + 1);
    }
    // debug(pref);
    // debug(mp[0]);
    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	if(pref[r] == pref[l - 1]) {
    		cout << "YES\n";
    	} else {
    		int flag = 1;
    		auto it = upper_bound(all(mp[pref[r]]), l - 1);
    		auto it2 = lower_bound(all(mp[pref[l - 1]]), r);
    		// debug(*it, *prev(it2,1), mp[pref[r]], mp[pref[l - 1]]);
    		if(it == mp[pref[r]].end() || *it >= r)
    			flag = 0;
    		if(it2 == mp[pref[l - 1]].begin() || *prev(it2, 1) <= l - 1)
    			flag = 0;
    		if(*it > *prev(it2, 1)){
    			flag = 0;
    		}
    		// debug(*it, *prev(it2, 1));
    		if(flag){
    			cout << "YES\n";
    		} else {
    			cout << "NO\n";
    		}
    	}
    }
    cout << "\n";
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