

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
    int oddmx = 0, evenmx = 0;
    int even = 0, odd = 0;
    multiset<int> evennum;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	if(a[i] & 1){
    		odd += 1;
    		oddmx = max(oddmx, a[i]);
    	}
    	else{ 
    		even += 1;
    		evenmx = max(evenmx, a[i]);
    		evennum.insert(a[i]);
    	}
    }
    if(odd == 0 || even == 0){
    	cout << "0\n";
    	return;
    }
    int ans = 0;
    int curr = oddmx;
    while(!evennum.empty()){
    	if(*evennum.begin() >= curr){
    		ans += evennum.size() + 1;
    		break;
    	} else {
    		ans += 1;
            curr += *evennum.begin();
    		evennum.erase(evennum.begin());
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