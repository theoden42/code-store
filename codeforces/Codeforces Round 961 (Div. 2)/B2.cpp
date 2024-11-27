

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
    int n, m;
    cin >> n >> m;
    vector<pair<int,int>>  a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i].first;
    for(int i = 0; i < n; i++)
    	cin >> a[i].second;
    sort(all(a));
    int ans = 0;
    for(int i = 0; i < n; i++){
    	int mxbuy = min(a[i].second, m / a[i].first);
    	int pt = mxbuy * a[i].first;
    	int rem = m - mxbuy * a[i].first;
    	if(i < n && a[i + 1].first == a[i].first + 1){
    		int nbuy = min(a[i + 1].second, rem / a[i + 1].first);
    		pt += nbuy * a[i + 1].first;
    		rem = rem % a[i + 1].first;
    		pt += min({rem, a[i + 1].second - nbuy, mxbuy});
    	}
    	ans = max(ans, pt);
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