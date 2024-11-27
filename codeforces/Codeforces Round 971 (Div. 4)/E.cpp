

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
    int lb = 0;
    int rb = n - 1;
    int ans = 1e18;

    while(lb <= rb){
    	int x = lb + (rb - lb) / 2;

    	int rsum = ((k + n - 1) * (k + n)) / 2 - ((k + x) * (k + x + 1)) / 2;
    	int lsum = ((k + x) * (k + x + 1)) / 2 - ((k - 1) * k) / 2;
    	ans = min(ans, abs(lsum - rsum));
    	if(rsum <= lsum){
    		rb = x - 1;
    	} else {
    		lb = x + 1;
    	}
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