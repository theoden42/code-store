

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

    if(n == 1){
    	cout << a[0] << "\n";
    	return;
    }

    vector<int> pre(n), suff(n);
    int ansf = 1e18;
    for(int i = 0; i < n; i++){
    	pre[i] = a[i] + (n - 1 - i);
    	suff[i] = a[i] + i;
    }
    for(int i = 1; i < n; i++){
    	pre[i] = max(pre[i], pre[i - 1]);
    }
    for(int i = n - 2; i >= 0; i--){
    	suff[i] = max(suff[i + 1], suff[i]);
    }

    for(int i = 0; i < n; i++){
    	int ans = 0;
    	if(i == 0)
    		ans = max({ans, a[i], suff[i + 1]});
    	else if(i == n - 1)
    		ans = max({ans, a[i], pre[i - 1]});
    	else 
    		ans = max({ans, a[i], suff[i + 1], pre[i - 1]});

    	ansf = min(ansf, ans);
    }
    cout << ansf << "\n";
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