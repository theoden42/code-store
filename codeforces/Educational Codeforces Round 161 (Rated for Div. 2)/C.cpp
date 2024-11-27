

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

    vector<int> love(n);
    love[0] = 1;
    love[n - 1] = -1;
    for(int i = 1; i < n - 1; i++){
    	if(a[i + 1] - a[i] < a[i] - a[i - 1]){
    		love[i] = 1;
    	} else {
    		love[i] = -1;
    	}
    }

    vector<int> pref(n + 1);
    vector<int> suff(n + 1);

    pref[1] = 0;
    suff[n] = 0;

    for(int i = 2; i <= n; i++){
    	if(love[i - 2] == 1){
    		pref[i] = pref[i - 1] + 1;
    	} else {
    		pref[i] = pref[i - 1] + a[i - 1] - a[i - 2];
    	}
    }

    for(int i = n - 1; i >= 1; i--){
    	if(love[i] == -1){
    		suff[i] = suff[i + 1] + 1;
    	} else {
    		suff[i] = suff[i + 1] + a[i] - a[i - 1];
    	}
    }

    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
    	int x, y;
    	cin >> x >> y;
    	int ans = 0;
    	if(y > x){
    		ans = pref[y] - pref[x];
    	} else {
    		ans = suff[y] - suff[x];
    	}
    	cout << ans << "\n";
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