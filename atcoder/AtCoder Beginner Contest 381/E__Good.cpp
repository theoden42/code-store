

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for(int i = 1; i <= q; i++){
    	int l, r;
    	cin >> l >> r;
    	l--;r--;
    	int ans = 0;
    	for(int j = l; j <= r; j++) if(s[j] == '/'){
    		int o = 0, t = 0;
    		for(int k = l; k < j; k++) if(s[k] == '1'){
    			o += 1;
    		}
    		for(int k = j + 1; k <= r; k++) if(s[k] == '2'){
    			t += 1;
    		}
    		int v = 2 * min(o, t) + 1;
    		ans = max(ans, v);
    	}
    	cout << ans << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}