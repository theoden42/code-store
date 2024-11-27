

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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    vector<int> difs(n + 1, 0);
    vector<int> pos(n + 1, 0), neg(n + 1);
    for(int i = 1; i < n; i++){
    	difs[i] = a[i] - a[i - 1];
    }
    for(int i = 1; i <= n; i++){
    	pos[i] = pos[i - 1];
    	neg[i] = neg[i - 1];
    	if(difs[i - 1] < 0){
    		neg[i] += abs(difs[i - 1]);
    	} else {
    		pos[i] += abs(difs[i - 1]);
    	}
    }

    for(int i = 0; i < q; i++){
    	int l, r, k;
    	cin >> l >> r >> k;
    	l--;
    	r--;
    	int possum = pos[r + 1] - pos[l + 1];
    	int negsum = neg[r + 1] - neg[l + 1];
    	int rem = max(possum, negsum) - min(possum, negsum);
    	if(possum + negsum <= k){
    		cout << 0 << "\n";
    		continue;
    	}
    	int sub = possum + negsum - k;
    	if(sub <= 2 * min(possum, negsum)){
    		cout << (sub + 1) / 2 << "\n";
    	} else {
    		int ans = sub - min(possum, negsum);
    		cout << max(0ll, ans) << "\n";
    	}
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