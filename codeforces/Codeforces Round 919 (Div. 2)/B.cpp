

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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
    	cin >> a[i];
    }
    sort(all(a));
    vector<int> pref(n + 1);
    for(int i = 1; i <= n; i++){
    	pref[i] = pref[i - 1] + a[i - 1];
    }
    int sum = pref[n];
    int mx = -1e18;
    for(int i = 0; i <= k; i++){
    	// remove i elements from the array
    	int lst = n - i;
    	int remsum = pref[n] - pref[n - i];
    	int minsum = pref[lst] - pref[max(0ll, lst - x)];
    	// debug(sum, remsum, 2 * minsum);
    	int finsum = sum - remsum - 2 * minsum;
    	mx = max(mx, finsum);
    }
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