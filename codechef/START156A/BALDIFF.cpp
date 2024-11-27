

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    int lb = 0;
    int ub = 1e12;
    int ans = 1e12;

    auto check = [&](int mid){
    	int lst = a[0] + mid;
    	for(int i = 1; i < n; i++){
    		if(a[i] <= lst){
                lst = min(a[i] + mid, lst + x);
    		} else if(lst + x >= a[i]){
    			lst = min(a[i] + mid, lst + x);
    		} else if(a[i] - lst - x <= mid){
    			lst = lst + x;
    		} else {
    			return false;
    		}
    	}
    	return true;
    };

    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		ans = mid;
    		ub = mid - 1;
    	} else {
    		lb = mid + 1;
    	}
    }

    a[0] += ans;
    for(int i = 1; i < n; i++){
	    if(a[i] <= a[i - 1]){
	    	a[i] = min(a[i] + ans, a[i - 1] + x);
		} else if(a[i - 1] + x >= a[i]){
			a[i] = min(a[i] + ans, a[i - 1] + x);
		} else if(a[i] <= a[i - 1] + x + ans){
			a[i] = a[i - 1] + x;
		} else {
			assert(false);
		}
    }

    cout << ans << "\n";
    for(int i = 0; i < n; i++){
    	cout << a[i] << " \n"[i == n - 1];
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