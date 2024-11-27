

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
    cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i];
    }

    auto check = [&](int x1, int y1, int x2, int y2, int x3, int y3){
        int a = x1 * (y2 - y3) + 
            x2 * (y3 - y1) + 
            x3 * (y1 - y2);
     	
        return (a == 0);
    };

    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		for(int k = j + 1; k < n; k++){
    			if(check(x[i], y[i], x[j], y[j], x[k], y[k])){
    				cout << "Yes\n";
    				return;
    			}
    		}
    	}
    }
    cout << "No\n";
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