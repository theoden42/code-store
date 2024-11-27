

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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; ++i){
    	pref[i] = pref[i - 1] + a[i - 1];
    }

    auto check = [&](int left, int right, int u){
    	if(right == n + 1){
    		right = n;
    	}
    	int sum = pref[right] - pref[left - 1];
    	int total = sum * u - ((sum * (sum - 1)) / 2);
    	return total;
    };

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++){
    	int l, u;
    	cin >> l >> u;
    	int lb = l;
    	int ub = n;
    	int ans = l;
    	while(lb <= ub){
    		int mid = (lb + ub) / 2;
    		int v1 = check(l, mid, u);
    		int v2 = check(l, mid + 1, u);
    		// debug(mid, v1, v2);
    		if(v1 < v2){
    			lb = mid + 1;
    		} else {
    			ans = mid;
    			ub = mid - 1;
    		}
    	}
    	cout << ans << " \n"[i == q];
    }

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