

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
    if(n == 		1){
    	cout << "0\n";
    	return;	
    }
    sort(all(a));
   	
   	int lb = 2e9 + 5;
   	int rb = 0;
   	for(int i = 0; i < n; i++){	
   		if(i < n - 1){
   			int d = a[i + 1] - a[i] + 1;
   			if(d < a[i] || d > a[i + 1])
   				continue;
   			// any value gte d should work 
   			lb = min(lb, d);
   		} 
   		if(i > 1){
   			int v = a[i] + a[i - 1] - 1;

   		}
   	}

    cout << ans << '\n';
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