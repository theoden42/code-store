

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
    int used_mx = 0;
    for(int i = 0; i < n; i++){
    	int l;
    	cin >> l;
    	vector<int> v;
    	for(int j = 0; j < l; j++){
    		int x;
    		cin >> x;
    		v.push_back(x);
    	}
    	sort(all(v));
    	int mx_t = 0;
    	for(int k = 0; k < l; k++){
    		if(v[k] == mx_t)
    			mx_t += 1;
    	}
        int mx_t2 = mx_t + 1;
        for(int k = 0; k < l; k++){
            if(v[k] == mx_t2){
                mx_t2 += 1;
            }
        }
        used_mx = max(used_mx, mx_t2);
    	// mx[mx_t] = mx_t2;
    }

    int ans = 0;
    if(m > used_mx){
    	int temp = m * (m + 1) / 2;
    	temp -= (used_mx * (used_mx + 1)) / 2;
    	ans += temp;
    }
    ans += used_mx * min(m + 1, used_mx + 1);
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