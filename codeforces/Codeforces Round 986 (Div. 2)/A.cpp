

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
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;	
    int x = 0, y = 0;
    int up = 0, left = 0;

    for(int i = 0; i < 100; i++){
    	for(int j = 0; j < n; j++){
    		if(s[j] == 'N'){
    			up += 1;
    		} else if(s[j] == 'S'){
    			up -= 1;
    		} else if(s[j] == 'E'){
    			left += 1;
    		} else {
    			left -= 1;
    		}
    		if(left == a && up == b){
    			cout << "YES\n";
    			return;
    		}
    	}
    }
    cout << "NO\n";
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