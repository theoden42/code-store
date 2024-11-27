

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
    int n, m, d;
    cin >> n >> m >> d;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    for(int i = 0; i < m; i++){
    	cin >> b[i];
    }
    sort(all(a));
    sort(all(b));

    int mx = -1;
    
    for(int i = 0; i < n; i++){
    	int x = a[i];
    	int y = a[i] + d;
    	auto it = upper_bound(all(b), y);
    	if(it == b.begin())continue;
    	else{
    		int val = *(--it);
    		if(abs(val - x) > d)continue;

    		mx = max(mx, x + val);
    	}
    }

    cout << mx << "\n";
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