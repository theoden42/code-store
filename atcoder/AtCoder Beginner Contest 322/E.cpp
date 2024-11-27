

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


#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, k, p;
    cin >> n >> k >> p;
   	vector<vector<int>> v(n, vector<int>(k + 1));
   	for(int i = 0; i < n; i++){
   		cin >> v[i][0];
   		for(int j = 1; j <= k; j++){
   			cin >> v[i][j];
   		}
   	}
   	map<pair<int, vector<int>>, int> dp;
   	function<int(int, vector<int>)> dfs 
    = [&](int ind, vector<int> state){
    	if(ind == n){
    		int flag = 1;
    		for(int i = 0; i < k; i++){
    			if(state[i] < p){
    				flag = 0;
    			}
    		}
    		if(flag){
    			return 0ll;
    		} else {
    			return (int)1e18;
    		}
    	}

    	if(dp.find({ind, state}) != dp.end())
    		return dp[{ind, state}];

    	int mxans = 1e18;
    	vector<int> newstate = state;
		for(int i = 0; i < k; i++){
			newstate[i] = min(p, state[i] + v[ind][i + 1]);
		}

		mxans = min(mxans, v[ind][0] + dfs(ind + 1, newstate));
		mxans = min(mxans, dfs(ind + 1, state));

		return dp[{ind, state}] = mxans;
    };

    vector<int> state(k, 0);
    int ans = dfs(0, state);
	if(ans >= 1e18){
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}

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