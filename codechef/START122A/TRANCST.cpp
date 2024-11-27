

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
    int t = n;

    if(n <= 1){
        cout << "0\n";
        return;
    }

    int count = 0;
    int left = 0;
    int right = -1;

    while(t != 0){
    	if(t & 1){
    		if(right == -1){
    			right = count;
    		}
    	} else {
    		left = count;
    	}
        debug(t & 1);
    	count += 1;
    	t >>= 1;
    }

    if(left <= right){
    	cout << "0\n";
        return;
    } 
    int val = 0;
    for(int j = 0; j < left; j++){
    	if(n >> j & 1){
    		val |= (1 << j);
    	}
    }

    int ans = (1 << left) - val;
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