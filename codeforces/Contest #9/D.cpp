

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
    sort(all(a));
    int val = 0;
    val = a[0] * a[n - 1];

    vector<int> new_val;
    for(int i = 2; i * i <= val; i++){
    	if(val % i == 0){
    		int f1 = i;
    		int f2 = val / i;
    		if(f1 != f2){
    			new_val.push_back(f1);
    			new_val.push_back(f2);
    		}else{
    			new_val.push_back(f1);
    		}
    	}
    }
    sort(all(new_val));
    if(new_val != a){
    	cout << "-1\n";
    	return;
    }
    cout << val << "\n";
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