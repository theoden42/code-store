

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
    int r;
    cin >> r;
    int ans = 0;

    auto check = [&](int r, int x){
    	int ly = 0;
    	int hy = r;
    	int ans = 0;
    	while(ly <= hy){
    		int mid = (ly + hy) / 2;
    		if(x * x + mid * mid < r * r){
    			ans = mid;
    			ly = mid + 1;
    		} else {
    			hy = mid - 1;
    		}
    	}

    	return ans;
    };

    for(int x = 0; x <= r; x++){
		int total = (check(r + 1, x) - check(r, x));
		ans += 4 * total;	
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