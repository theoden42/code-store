

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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    for(int i = 0; i < n; i++)
    	cin >> b[i];
    int sum_a = 0, sum_b = 0;
    int c1 = 0, c2 = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] != b[i]){
    		if(a[i] > b[i])
    			sum_a += a[i];
    		else
    			sum_b += b[i];
    	} else {
    		if(a[i] == 1){
    			c1++;
    		} else if(a[i] == -1) {
    			c2++;
    		}
    	}
    }
    auto check = [&](int v){
    	int t_1 = c1, t_2 = c2;
    	if(sum_a < v){
    		if(v - sum_a > t_1)
    			return false;
    		t_1 -= (v - sum_a);
    	} else {
    		t_2 -= min(t_2, (sum_a - v));
    	}
    	debug(v, t_1, t_2);
    	int val2 = sum_b + t_1 - t_2;
    	// debug(val2, v);
    	return (val2 >= v);
    };
    int lb = -n;
    int ub = n;
    int ans = -n;
    while(lb <= ub){
    	int mid = lb + (ub - lb) / 2;
    	if(check(mid)){
    		ans = mid;
    		lb = mid + 1;
    	} else {
    		ub = mid - 1;
    	}
    }
    cout << ans << '\n';
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}