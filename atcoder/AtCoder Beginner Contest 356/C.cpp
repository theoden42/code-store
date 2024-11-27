

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
    int n, m, k;
    cin >> n >> m >> k;


    vector<int> c(m);
    vector<vector<int>> v(m, vector<int>());
    vector<int> r(m);

    for(int i = 0; i < m; i++){
    	cin >> c[i];
    	for(int j = 0; j < c[i]; j++){
    		int x;
    		cin >> x;
    		v[i].push_back(x);
    	}
    	char rt;
    	cin >> rt;
    	if(rt == 'o')
    		r[i] = 1;
    }

    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++){
    	int flag = 1;
    	for(int i = 0; i < m; i++){
    		int count = 0;
    		for(auto vt: v[i]){
    			vt -= 1;
    			if(mask >> vt & 1)
    				count += 1;
    		}
    		if((count >= k && r[i] == 0) || (count < k && r[i] == 1))
    			flag = 0;
    	}
    	if(flag){
    		ans += 1;
    	}
    }

    cout << ans << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}