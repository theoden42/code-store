

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
    int n;
    n = rng() % 10;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	a[i] = rng() % 20;
    }

    int mx = 0;
    int val = 0;

    for(int i = 1; i < (1 << n) - 1; i++){
    	int x = 0;
    	int y = 0;
    	for(int j = 0; j < n; j++){
    		if(i >> j & 1){
    			x |= a[j];
    		}
    		else{
    			y |= a[j];
    		}
    	}

    	int c = (x ^ y);
    	if(c > mx){
    		mx = c;
    		val = i;
    	}
    }
    debug(a);
    cout << mx << " " << val << "\n";
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