

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
    vector<int> zero(n), one(n), qu(n);
    for(int i = 0; i < m; i++){
    	string s;
    	cin >> s;
    	for(int j = 0; j < n; j++){
    		if(s[j] == '0')
    			zero[j] += 1;
    		else if(s[j] == '1')
    			one[j] += 1;
    		else 
    			qu[j] += 1;
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	int z = zero[i];
    	int o = one[i];
    	int q = qu[i];
    	if(min(z, o) + q <= max(z, o)){
    		int temp = max(z, o) * (min(z, o) + q);
    		ans += temp;
    	} else {
    		int dif = max(z, o) - min(z, o);
    		q -= dif;	
    		z = max(z, o);
    		o = max(z, o);
    		z += q / 2;
    		o += (q - q / 2);
    		ans += z * o;
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