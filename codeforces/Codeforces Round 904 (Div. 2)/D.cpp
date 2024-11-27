

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
    vector<int> mp(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mp[a[i]] += 1;
    }

    vector<int> gd(n + 1);
    vector<int> pr(n + 1);
    for(int i = n; i >= 1; i--){
    	int count = 0;
    	for(int j = 1; j * i <= n; j++){
    		count += mp[j * i];
    	}
    	count = (count * (count - 1)) / 2;
    	gd[i] = count;
    	for(int j = 2; j * i <= n; j++){
    		gd[i] -= gd[j * i];
    	}
    }

    for(int i = 1; i <= n; i++){
    	if(mp[i] == 0)
    		continue;
    	for(int j = 1; j * i <= n; j++){
    		pr[j * i] = 1;
    	}
    }

    int ans = (n * (n - 1)) / 2;
    for(int i = 1; i <= n; i++){
    	if(pr[i]){
    		ans -= gd[i];
    	}
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