

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
 	vector<int> a(n), b(n);
 	for(int i = 0; i < n; i++){
 		cin >> a[i];
 	}   
 	for(int i = 0; i < n; i++){
 		cin >> b[i];
 	}
 	vector<int> mx(n), pref(n + 1);
 	for(int i = 0; i < n; i++){
 		mx[i] = (a[i] / b[i]);
 		pref[i + 1] += pref[i];
 		pref[i + 1] += mx[i];
 	}

    debug(mx, pref);

 	int sum = accumulate(all(mx), 0ll);
 	for(int i = 0; i < n; i++){
 		int lb = 0;
 		int ub = mx[i];
 		int ans = 0;
 		while(lb <= ub){
 			int mid = lb + (ub - lb) / 2;
 			int sm = mid + pref[n] - pref[i + 1];
            // debug(mid, sm);
 			if(sm >= k){
 				ans = mid;
 				ub = mid - 1;
 			} else {
 				lb = mid + 1;
 			}
 		}
 		cout << ans << " \n"[i == n - 1];
        k -= ans;
 	}

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}