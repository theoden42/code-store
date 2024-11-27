

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
    int n;
    cin >> n;

    int ans = 0;

    for(int i = (n + 1) / 2; i <= n; i++){
    	for(int j = (n + 1) / 2; j <= n; j++){
    		int mxval = i * j;b
    		set<int> st;
    		for(int k = 1; k <= n; k++){
    			if(k != j){
    				st.insert(k);
    			}
    		}
    		int sum = 0;
    		int flag = 1;
    		for(int k = n; k >= 1; k--){
    			if(k == i)
    				continue;

    			int val = mxval / k;
    			auto it = st.upper_bound(val);
    			if(it == st.begin()){
    				flag = 0;
    				break;
    			}
    			--it;
    			sum += (*it) * k;
    			st.erase(it);
    		}
    		if(!flag)
    			continue;
    		// debug(i, j);
    		ans = max(ans, sum);
    	}	
    }

    // debug(ansi, ansj);

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