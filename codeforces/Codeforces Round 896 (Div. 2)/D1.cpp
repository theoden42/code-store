
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
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    int sum = 0;
    sum = accumulate(all(a), 0ll);

    if(sum % n != 0){
    	cout << "No\n";
    	return;
    }

    int donatevalue = 0;
    int avg = sum / n;

    for(int i = 0; i < n; i++){
    	int count = 0;
    	for(int j = 62; j >= 0; j--){
    		count *= 2;
    		if(count > 0 && (avg >> j & 1ll) && !(a[i] >> j & 1ll)){
    			count -= 1;
    		} 
    		else if(!(avg >> j & 1ll) && (a[i] >> j & 1ll)){
    			count += 1;
    		}
    	}
    	donatevalue += count;
    	a[i] -= count;
    }

    debug(a, sum, donatevalue);

    vector<int> vis(n + 1);
    for(int i = 0; i < n; i++){
    	for(int j = 63; j >= 0; j--){
    		if((avg >> j & 1ll) && !(a[i] >> j & 1ll)){
    			if(vis[i]){
    				cout << "No\n";
    				return;
    			}
    			if(donatevalue >= (1ll << j)){
    				donatevalue -= (1ll << j);	
    			} else {
    				cout << "No\n";
    				return;
    			}
    			vis[i] = 1;
    		}
    	}
    }

    if(donatevalue != 0){
    	cout << "No\n";
    	return;
    }

    cout << "Yes\n";

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