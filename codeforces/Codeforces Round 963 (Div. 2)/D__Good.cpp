

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

vector<int> dp(5e5 + 5, 0);

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
    	cin >> a[i];

   	int rem = n;
   	while(rem > k){
   		rem -= k;
   	}

    int lb = 0;
    int ub = 1e9;
    int ans = 0;
    auto check = [&](int mid){
    	for(int i = 0; i < rem; i++){
    		dp[i] = 0;
    	}
    	for(int i = 0; i < n; i++){
    		int v = (a[i] >= mid);
    		if(i % k == 0){
    			dp[0] = max(dp[0], v);
    			if(i > 0)
    				dp[k] = max(dp[k], dp[k - 1] + v);
    		} else {
    			dp[i % k] = max(dp[i % k], dp[i % k - 1] + v);
    		}
    	}
    	return (dp[rem - 1] >= rem - (rem + 1) / 2 + 1);
    };
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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}