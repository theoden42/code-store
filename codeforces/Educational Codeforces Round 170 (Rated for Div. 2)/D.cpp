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
    vector<int> df(m + 2, 0);
    int cnt = 0;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	if(x == 0){
    		for(int j = 1; j <= m; j++){
    			df[j] += df[j - 1];
    		}
    		vector<int> temp(m + 2);
    		temp[0] = df[0];
    		for(int j = 1; j <= m; j++){
    			temp[j] = max(df[j], df[j - 1]);
    		}
    		for(int j = 0; j <= m + 1; j++){
    			df[j] = temp[j];
    		}
    		temp.assign(m + 2, 0);
    		temp[0] = df[0];
    		for(int j = 1; j <= m + 1; j++){
    			temp[j] = df[j] - df[j - 1];
    		}
    		df.assign(all(temp));
    		cnt += 1;
    	} else {
    		if(x > 0){
    			if(x > cnt)
    				continue;
    			df[x] += 1;
    			df[m + 1] -= 1;
    		} else {
    			x = -x;
    			if(cnt - x >= 0){
    				df[0] += 1;
    				df[cnt - x + 1] -= 1;
    			}
    		}
    	}
    }
    int ans = df[0];
    for(int j = 1; j <= m; j++){
    	df[j] += df[j - 1];
    	ans = max(ans, df[j]);
    }
    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}