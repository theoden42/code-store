

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

# define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v;
    int ans = 1;
    function<void(int,int)> dfs
    = [&](int n, int k){
    	if(n < k){
    		ans = 0;
    		return;
    	}
    	if(n % k == 0){
    		v.push_back(n / k);
    		return;
    	}
    	int x = n / k;
    	if(n / x == k){
    		v.push_back(x);
    		return;
    	}
    	for(int d = x + 1; d <= k; d++){
    		if(n % d != 0){
    			int num = n / d;
    			v.push_back(d);
    			dfs(n - num * d, k - num);
    			return;
    		}
    	}
    }; dfs(n, k);

    if(!ans){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";
    cout << v.size() << "\n";
    for(int i = 0; i < v.size(); i++){
    	cout << v[i] << " \n"[i == v.size() - 1];
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