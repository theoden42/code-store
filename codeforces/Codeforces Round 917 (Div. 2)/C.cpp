
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
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<int> v(k);
    for(int i = 0; i < k; i++){
    	cin >> v[i];
    }

    int ans = 0;

    for(int i = 0; i <= 3 * n && i < d; i++){
    	int count = 0;
    	for(int j = 0; j < n; j++){
    		if(a[j] == j + 1)
    			count += 1;
    	}
    	int val = count + (d - i - 1) / 2;
    	ans = max(ans, val);

    	int ind = v[i % k];
    	for(int j = 0; j < ind; j++)
    		a[j] += 1;

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