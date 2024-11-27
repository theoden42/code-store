

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

    auto check = [&](int k){
    	int mnsum = 1e18;
    	int mxsum = 0;
    	for(int i = 0; i < n; i += k){
    		int sum = 0;
    		for(int j = i; j < i + k; j++){
    			sum += a[j];
    		}
	    	mnsum = min(sum, mnsum);
    		mxsum = max(sum, mxsum);
    	}
    	return mxsum - mnsum;
    };

    int mx = 0;
    for(int i = 1; i * i <= n; i++){
    	if(n % i == 0){
    		int f1 = i;
    		int f2 = n / i;
    		int a1 = check(f1);
    		int a2 = check(f2);
    		mx = max({mx, a1, a2});
    	}
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