

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
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    vector<int> p(n + 1);
    vector<vector<int>> adj(n + 1);
    for(int i = 2; i <= n; i++){
    	cin >> p[i]; 
    	adj[p[i]].push_back(i);
    }

    vector<int> heights(n + 1, -1);
    function<void(int, int)> dfs = [&](int source, int h){
    	heights[source] = h;
    	for(auto node: adj[source]){
    		dfs(node, h + 1);
    	}
    };dfs(1, 0);

    vector<int> h_sum(n + 1);
    for(int i = 0; i <= n; i++){
    	if(heights[i] != -1){
    		h_sum[heights[i]] += a[i];
    	}
    }

    for(int i = n; i >= 0; i--){
    	if(h_sum[i] == 0){
    		continue;
    	} else if(h_sum[i] > 0){
    		cout << "+\n";
    		return;
    	} else {
    		cout << "-\n";
    		return;
    	}
    }

    cout << "0\n";
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