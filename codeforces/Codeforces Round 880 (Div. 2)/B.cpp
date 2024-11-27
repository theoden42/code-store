

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
    int n, k, g;
    cin >> n >> k >> g;	

    if(n == 1){
    	cout << 0 << "\n";
    	return;
    }

    int a1 = n * ((g + 1) / 2 - 1);

    if(a1 >= k * g){
    	cout << k * g << "\n";
    }
    else{
    	int val1 = (n - 1) * ((g + 1) / 2 - 1);
    	int dif = (k * g) - val1;
    	int r = dif % g;

    	if(r >= (g + 1) / 2){
            
    		r = -1 * (g - r);
    	}

    	int ans = val1 + r;
    	cout << ans << "\n";
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