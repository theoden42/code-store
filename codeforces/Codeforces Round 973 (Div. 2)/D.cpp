
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
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    auto check = [&](int x){
    	int val = 0;
    	for(int i = 0; i < n; i++){
    		if(a[i] > x){
    			val += (a[i] - x);
    		} else {
    			if(x - a[i] > val)
    				return 0;
    			val -= (x - a[i]);
    		}
    	}
    	return 1;
    };

    int lb = 0;
    int ub = a[0];
    int mn_val = a[0];
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		mn_val = mid;
    		lb = mid + 1;
    	} else {
    		ub = mid - 1;
    	}
    }

	auto check2 = [&](int mid)->int{
		int mx = mn_val + mid;
		vector<int> b(a.begin(), a.end());
		int extra = 0;
		for(int i = 0; i < n; i++){
			if(b[i] > mx){
				extra += b[i] - mx;
				b[i] = mx;
			} else {
				int left = mx - b[i];
				int temp = min(extra, left);
				extra -= temp;
				b[i] += temp;
			}
		}
		if(extra > 0)
			return 0;
		extra = 0;
		for(int i = 0; i < n; i++){
			if(b[i] >= mn_val){
				extra += b[i] - mn_val;
			} else{
				int left = mn_val - b[i];
				if(left > extra)
					return 0;
				else 
					left -= extra;
			}
		}
		return 1;
	};

	debug(mn_val);

    lb = 0;
    ub = 1e18;
    int ans = ub;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check2(mid)){
    		ans = mid;
    		ub = mid - 1;
    	} else {
    		lb = mid + 1;
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