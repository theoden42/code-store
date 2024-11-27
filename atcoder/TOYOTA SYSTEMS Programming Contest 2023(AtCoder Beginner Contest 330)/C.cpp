

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
    int d;
    cin >> d;
    int mnans = 1e18;
    for(int i = 1; (i - 1) * (i - 1) <= d; i++) {
    	int l = 0;
    	int u = i;
    	int x = i;
    	int mncurr = 1e18;
    	while(l <= u){
    		int y = l + (u - l) / 2;
    		int val = x * x + y * y;
    		int diff = abs(d - val);
    		mncurr = min(mncurr, diff);
    		if(val >= d){
    			u = y - 1;
    		} else {
    			l = y + 1;
    		}
    	}
        mnans = min(mnans, mncurr);
    }

    cout << mnans << "\n";
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