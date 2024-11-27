

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
    vector<int> pre(n + 1);
    vector<int> one(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
    	pre[i] = pre[i - 1];
    	one[i] = one[i - 1];
    	pre[i] += a[i - 1] - 1;
    	if(a[i - 1] == 1)
    		one[i] += 1;
    }

    for(int i = 0; i < q; i++){
    	int l, r;
    	cin >> l >> r;
    	if(r == l){
    		cout << "NO\n";
    		continue;
    	}
    	int sum = pre[r] - pre[l - 1];
    	int cn = one[r] - one[l - 1];
    	if(sum < cn){
    		cout << "NO\n";
    	} else {
    		cout << "YES\n";
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