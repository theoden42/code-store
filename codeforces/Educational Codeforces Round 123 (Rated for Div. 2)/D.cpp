

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


    map<int, int> row, col;
    for(int i = 0; i < q; i++){
    	int r, c;
    	cin >> r >> c;
    	r--;
    	c--;
    	row[r] = i;
    	col[c] = i;
    }

    multiset<int> mst1, mst2;
    set<int> st;
    for(auto& it : row){
    	mst1.insert(it.second);
    }
    for(auto& it: col){
    	mst2.insert(it.second);
    }

   	for(auto [key, val]: col){
   		auto it = mst1.upper_bound(val);
   		if(row.size() < n || it != mst1.begin()){
   			st.insert(val);
   		}
   	}

   	for(auto [key, val]: row){
   		auto it = mst2.upper_bound(val);
   		if(col.size() < m || it != mst2.begin())
   			st.insert(val);
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