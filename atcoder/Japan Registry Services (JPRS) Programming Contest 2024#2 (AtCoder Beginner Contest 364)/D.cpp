

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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    sort(all(a));
    vector<int> b(q), k(q);
    for(int i = 0; i < q; i++)
    	cin >> b[i] >> k[i];

    for(int i = 0; i < q; i++){
    	int l = 0;
    	int u = 1e9;
    	int ans = 1e9;
    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		int left = b[i] - mid;
    		int right = b[i] + mid;
    		auto ind2 = upper_bound(all(a), right) - a.begin();
    		auto ind1 = lower_bound(all(a), left) - a.begin();
    		int num = ind2 - ind1;
    		if(num >= k[i]){
    			ans = mid;
    			u = mid - 1;
    		} else {
    			l = mid + 1;
    		}
    	}
    	cout << ans << "\n";
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