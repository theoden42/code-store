

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
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    auto check = [&](int x, int y, int x1, int x2, int y1, int y2){
    	int d = (y - y1) * (x2 - x1) - (x - x1) * (y2 - y1);
    	return d;
    };
    int val = check(x3, y3, x1, x2, y1, y2);
    int val2;
    if(y1 < y2)
    	val2 = check(x1 - 1, y1, x1, x2, y1, y2);
    else 
    	val2 = -check(x2 - 1, y2, x1, x2, y1, y2);

    if(val2 == 0){
    	if(x1 < x2)
    		val2 = check(x1, y1 + 1, x1, x2, y1, y2);
    	else 
    		val2 = check(x1, y1 - 1, x1, x2, y1, y2);
    }

    if(val == 0){
    	cout << "TOUCH\n";
    } else if(((val > 0) ^ (val2 > 0)) == 0){
    	cout << "LEFT\n";
    } else {
    	cout << "RIGHT\n";
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