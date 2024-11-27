

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
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    vector<int> val(w);
    for(int i = 0; i < w; i++){
    	cin >> val[i];
    }
    sort(all(val));

    vector<vector<int>> pref(n + 2, vector<int>(m + 2));

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(i - k + 1 < 1ll || j - k + 1 < 1ll)
    			continue;
    		int top = i - k + 1;
    		int bottom = i;
    		int left =  j - k + 1;
    		int right = j;
    		pref[top][left] += 1;
    		pref[top][right + 1] -= 1;
    		pref[bottom + 1][left] -= 1;
    		pref[bottom + 1][right + 1] += 1;
    	}
    }

    for(int i = 1; i <= n + 1; i++){
    	for(int j = 1; j <= m + 1; j++){
    		pref[i][j] += pref[i - 1][j];
    		pref[i][j] += pref[i][j - 1];
    		pref[i][j] -= pref[i - 1][j - 1];
    	}
    }

    vector<int> mx;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		mx.push_back(pref[i][j]);
    	}
    }
    int ans = 0;
    sort(all(mx));
    while(!val.empty()){
    	int sum = mx.back() * val.back();
    	mx.pop_back();
    	val.pop_back();
    	ans += sum;
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