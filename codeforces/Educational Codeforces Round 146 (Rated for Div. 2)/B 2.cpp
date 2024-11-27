

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
    int a, b;
    cin >> a >> b;
    int m1 = min(a, b);
    int m2 = max(a, b);

    int l = 2;
    int u = m2;
    int ind = m2;

    while(l <= u){
    	int mid = l + (u - l) / 2;
    	int x1 = (m2 + mid - 1) / mid + mid - 1;
    	int x2 = (m2 + mid - 2) / (mid - 1) + mid - 2;
    	if(x1 <= x2){
    		ind = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
    	}
    }

    // debug(ind);

    int mx = (m1 + ind - 1) / ind + (m2 + ind - 1) / ind + ind - 1;

    cout << mx << "\n";
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