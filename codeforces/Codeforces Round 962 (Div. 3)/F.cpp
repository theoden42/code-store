

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
    cin >> n  >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int i = 0; i < n; i++)
    	cin >> b[i];

    int lb = 0;
    int ub = *max_element(all(a));
    int x = ub;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;	
    	int tot = 0;
    	for(int i = 0; i < n; i++){
    		int op = max(0ll, (a[i] - mid + b[i] - 1) / b[i]);
    		tot += op;
    	}
    	if(tot <= k){
    		x = mid;
    		ub = mid - 1;
    	} else {
    		lb = mid + 1;
    	}
    }
    int ans = 0;
    multiset<pair<int,int>> mst;
    for(int i = 0; i < n; i++){
    	int t = max(0ll, (a[i] - x + b[i] - 1) / b[i]);
    	k -= t;
    	ans += (t * (a[i] + a[i] - (t - 1) * b[i])) / 2;
    	if(a[i] - t * b[i] > 0)
    		mst.insert({a[i] - t * b[i], i});
    }

    while(k > 0 && !mst.empty()){
    	auto [val, ind] = *prev(mst.end(), 1);
    	mst.erase(prev(mst.end(), 1));
    	ans += val;
    	val -= b[ind];
    	if(val > 0)
    		mst.insert({val, ind});
    	k -= 1;
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