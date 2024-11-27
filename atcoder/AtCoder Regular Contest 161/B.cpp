

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
    ll n;
    cin >> n;
    if(n < 7){
    	cout << "-1\n";
    	return;
    }

    if(__builtin_popcountll(n) >= 3){
    	ll ans = 0;
	    int count = 0;

	    for(int i = 60; i >= 0 && count < 3; i--){
	    	if(n >> i & 1ll){
	    		ans += (1ll << i);
	    		count++;
	    	}
	    }

	    cout << ans << "\n";
    }

   	else if(__builtin_popcountll(n) == 1){
   		ll ans = 0;
   		for(int i = 60; i >= 0; i--){
   			if(n >> i & 1ll){

   				ans += (1ll << (i - 1));
   				ans += (1ll << (i - 2));
   				ans += (1ll << (i - 3));
   				break;
   			}
   		}
   		debug(ans);
   		cout << ans << "\n";
   	}
   	else{
   		ll ans = 0;
   		int ind = 0;
   		int ind2 = 0;
   		for(int i = 60; i >= 0; i--){
   			if(n >> i & 1ll){
   				ind = i;
   				break;
   			}
   		}

   		for(int i = 0; i < 61; i++){
   			if(n >> i & 1ll){
   				ind2 = i;
   				break;
   			}
   		}

   		if(ind2 >= 2){
   			ans += (1ll << ind);
   			ans += (1ll << (ind2 - 1));
   			ans += (1ll << (ind2 - 2));
   		}
   		else{
   			ans += (1ll << (ind - 1));
   			ans += (1ll << (ind - 2));
   			ans += (1ll << (ind - 3));
   		}
   		cout << ans << "\n";
   	}



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