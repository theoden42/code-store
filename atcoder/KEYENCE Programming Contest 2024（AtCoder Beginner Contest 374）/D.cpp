

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
    int n, s, t;
    cin >> n >> s >> t;
    vector<vector<int>> pt(n);
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 4; j++){
    		int x;
    		cin >> x;
    		pt[i].push_back(x);
    	}
    }
    sort(all(pt));
    ld ans = 1e18;
    do {
    	for(int bit = 0; bit < (1 << n); bit++){
    		int lstx = 0, lsty = 0;
	    	ld sum = 0;
	    	// debug(pt);
	    	for(int i = 0; i < n; i++){
	    		int a = pt[i][0], b = pt[i][1], c = pt[i][2], d = pt[i][3];
	    		if((bit >> i) & 1){
	    			swap(a, c);
	    			swap(b, d);
	    		}	
	    		// debug(a, b, c, d);
	    		ld dst = (a - lstx) * (a - lstx) + (b - lsty) * (b - lsty);
	    		ld ldst = (c - a) * (c - a) + (d - b) * (d - b);
	    		ld t_ans = sqrtl(dst) / ((ld)s) + sqrtl(ldst) / ((ld)t);
	    		sum += t_ans;
	    		lstx = c;
	    		lsty = d;
	    	}
	    	ans = min(ans, sum);
    	}
    } while(next_permutation(all(pt)));
    cout << fixed << setprecision(15) << ans << "\n";
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