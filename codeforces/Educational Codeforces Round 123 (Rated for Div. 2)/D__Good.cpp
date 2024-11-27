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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

void solve() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> row(n, -1), col(m, -1);

    for(int i = 0; i < q; i++){
    	int r, c;
    	cin >> r >> c;
    	r--;
    	c--;
    	row[r] = i;
    	col[c] = i;
    }

    set<int> st;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		int val = max(row[i], col[j]);
    		if(val != -1){
    			st.insert(val);
    		}
    	}
    }

    int sz = st.size();
    int ans = 1;

    for(int i = 1; i <= sz; i++){
    	ans *= k;
    	ans %= MOD;
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