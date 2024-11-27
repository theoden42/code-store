

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
    int n, q;
    cin >> n >> q;
    int sz = 0;
    map<int,int> add;
    vector<int> value;
    for(int i = 0; i < n; i++){
    	int b, x;
    	cin >> b >> x;
    	if(b == 1){
    		add[sz] = x;
    		sz += 1;
    	} else {
    		value.push_back(sz);
    		int v = (2e18) / sz;
    		sz *= min(x + 1, v);
    	}
    }

    // debug(value, add);

    function<int(int)> get = [&](int ind){ 
    	// debug(ind);
    	if(add.find(ind) != add.end())
    		return add[ind];
    	auto x = upper_bound(all(value), ind);
    	x--;
    	int tempsz = *x;
    	return get(ind % tempsz);
    };

    for(int i = 1; i <= q; i++){
    	int k;
    	cin >> k;
    	k -= 1;
    	int ans = get(k);
    	cout << ans << " \n"[i == q];
    }
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