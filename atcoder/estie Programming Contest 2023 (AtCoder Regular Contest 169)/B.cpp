

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
   int n, s;
   cin >> n >> s;
   vector<int> v(n);
   vector<int> pref(n + 1);
   for(int i = 0; i < n; i++){
   	cin >> v[i];
   }	
   for(int i = 1; i <= n; i++){
   	pref[i] = pref[i - 1] + v[i - 1];
   }

   vector<int> dp(n + 2, 0);
   for(int l = n; l >= 1; l--){
   	  int low = l;
   	  int high = n;
   	  int ans = l;
   	  while(low <= high){
   	  	int mid = low + (high - low) / 2;
   	  	int val = pref[mid] - pref[l - 1];
   	  	if(val <= s){
   	  		ans = mid;
   	        low = mid + 1;
   	  	} else {
            high = mid - 1;
   	  	}
   	  }
      // debug(l, ans);
   	  dp[l] = (ans - l + 1) + (n - ans) + dp[ans + 1];
   }

   // debug(dp);

   int finsum = 0;
   for(int l = 1; l <= n; l++){
   	finsum += dp[l];
   }
   cout << finsum << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}