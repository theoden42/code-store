

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
   	int n; ld p;
    cin >> n >> p;
    p /= 100;		
	ld prob = 1;

	for(int i = 0; i < n - 1; i++){
		debug(prob);
		prob *= p;
	}
	debug(prob);
    ld lb = 0;
    ld ub = 1 - p;
    ld ans = ub;
    while(ub - lb > 1e-9){
    	ld mid = lb + (ub - lb) / 2;	
    	ld nprob = 1;
    	for(int x = 1; x <= n; x++){
    		nprob *= (1.0d * p + mid);
    	}
    	if(nprob >= prob){
    		ans = mid;
    		ub = mid;
    	} else {
    		lb = mid;
    	}
    }

    cout << fixed << setprecision(9) << ans * 100 << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}