

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
    vector<int> a(n), b(n - 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++){
    	cin >> b[i];
    }
    sort(all(a));
    reverse(all(a));
    auto check = [&](int mid){
    	multiset<int> mst;
    	for(auto x: b){
    		mst.insert(x);
    	}
    	mst.insert(mid);
    	for(auto x: a){
    		auto it = mst.lower_bound(x);
    		if(it != mst.end()){
    			mst.erase(it);
    		} else {
    			return false;
    		}
    	}
    	return true;
    };
    int lb = 0;
    int ub = 1e9 + 5;
    int ans = 1e9 + 5;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		ans = mid;
    		ub = mid - 1;
    	} else {
    		lb = mid + 1;
    	}
    }
    if(ans == 1e9 + 5){
        cout << "-1\n";
        return;
    }
    cout << ans << "\n";
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