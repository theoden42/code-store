

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
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n), p(n), q(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i] >> p[i] >> b[i] >> q[i];
    }

    auto get = [&](int i, int w){
    	// ma + nb >= w & mp + nq is minimum possible
    	int ai = a[i], bi = b[i], pi = p[i], qi = q[i];
    	if((ai >= bi && pi <= qi) || (ai <= bi && pi >= qi)){
    		int ans = ((w + max(ai, bi) - 1) / max(ai, bi)) * min(pi, qi);
    		return ans;
    	}
    	int m = (w + max(ai, bi) - 1) / max(ai, bi);
    	int c = m * max(pi, qi);
    	// m * max(a[i], bi) - x * (max(ai, bi) - min(ai, bi)) >= w
    	int d = max(ai, bi) - min(ai, bi);
    	int x = (m * max(ai, bi) - w) / d;
    	c -= x * (max(pi, qi) - min(pi, qi));
    	return c;
    };

  	auto check = [&](int w){
  		// all machines have output atleast w 
  		int tx = x;
  		for(int i = 0; i < n; i++){
  			int gt = get(i, w); 
  			// debug(gt, w);
  			if(tx < gt)
  				return false;
  			else 
  				tx -= gt;
  		}
  		return true;
  	};

    int lb = 0;
    int ub = 1e9 + 5;
    int ans = 0;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		ans = mid;
    		lb = mid + 1;
    	} else {
    		ub = mid - 1;
    	}
    }
    cout << ans << "\n";
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