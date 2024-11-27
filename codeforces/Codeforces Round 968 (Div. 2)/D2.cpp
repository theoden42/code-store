

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
    vector<vector<int>> seq(n);
    int mx_l = 0;
    for(int i = 0; i < n; i++){
    	int l;
    	cin >> l;
    	for(int j = 0; j < l; j++){
    		int x;
    		cin >> x;
    		seq[i].push_back(x);
    	}
    	sort(all(seq[i]));
    	mx_l = max(mx_l, l); 
    }
    vector<vector<int>> adj(mx_l + 1);
    vector<int> mx_count(mx_l + 1);	
    for(int i = 0; i < n; i++){
    	int mx_1 = 0;
    	for(auto& x: seq[i]){
    		if(x == mx_1)
    			mx_1 += 1;
    	}
    	int mx_2 = mx_1 + 1;
    	for(auto& x: seq[i]){
    		if(x == mx_2)
    			mx_2 += 1;
    	}
    	mx_count[mx_1] += 1;
    	adj[mx_1].push_back(mx_2);
    }
    int ans = 0;
    if(m > mx_l){
    	int t = (m * (m + 1)) / 2;
    	t -= ((mx_l + 1) * mx_l) / 2;
    	ans += t;
    }

    vector<int> dp(mx_l + 1, -1);
    function<int(int)> dfs = [&](int source){
    	if(dp[source] != -1)
    		return dp[source];
    	dp[source] = source;
    	int temp = 0;
    	for(auto& x: adj[source]) {
    		if(x > mx_l){
    			temp = max(temp, x);
    		} else {
    			temp = max(temp, dfs(x));
    		}
    	}
    	dp[source] = max(dp[source], temp);
    	return dp[source];
    };
    for(int i = 0; i <= mx_l; i++){
    	if(dp[i] == -1){
    		dfs(i);
    	}
    }

    int t_val = 0;
    for(int i = 0; i <= mx_l; i++){
    	if(mx_count[i] >= 1){
    		t_val = max(t_val, i);
    	} 
    	if(mx_count[i] >= 2){
    		t_val = max(t_val, dp[i]);
    	}
    }
    for(int i = 0; i <= min(m, mx_l); i++){
    	int fin = max({i, t_val, dp[i]});
    	ans += fin;
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