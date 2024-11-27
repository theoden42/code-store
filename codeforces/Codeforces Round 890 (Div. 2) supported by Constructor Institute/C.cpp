

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
const ll INF = 1e16;

#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int mx = *max_element(all(a));

    int low = mx;
    int ans = mx;
    int high = 1e10;

    function<int(int, int)> recur 
    = [&](int index, int value){	
    	if(a[index] >= value)
    		return 0ll;
    	if(index >= n - 1)
    		return INF;

    	int coins = value - a[index];
    	coins += recur(index + 1, value - 1);
    	return coins;
    };

    auto check = [&](int val){
    	int flag = 0;
    	for(int i = 0; i < n; i++){
    		// can I make a[i] equal to val;
    		// debug(a[i]);
    		if(a[i] >= val){
    			flag = true;
    			break;
    		}
    		int coins = 0;
    		coins += recur(i, val);
    		// debug(coins);
    		if(coins <= k){
    			flag = true;
    			break;
    		}
    	}
    	return flag;
    };

    while(low <= high){
    	int mid = (low + high) / 2;
    	// debug(mid);
    	if(check(mid)){
    		ans = max(ans, mid);
    		low = mid + 1;;
    	} else {
    		high = mid - 1;
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