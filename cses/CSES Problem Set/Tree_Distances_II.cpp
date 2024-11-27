

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
    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; i++){
    	int a, b;
    	cin >> a >> b;
    	a--;
    	b--;
    	adj[a].push_back(b);
    	adj[b].push_back(a);
    }

    vector<int> sz(n), dis(n);
    function<int(int, int, int)> dfs = [&](int source, int parent, int d){
    	int count = 1;
        dis[source] = d;
    	for(auto x: adj[source]){
    		if(x == parent)
    			continue;
    		count += dfs(x, source, d + 1);
    	}
    	sz[source] = count;	
    	return count;
    };
    dfs(0, -1, 0);

    int temp = 0;
    for(int i = 0; i < n; i++){
        temp += dis[i];     
    }

    vector<int> ans(n);
    function<void(int, int, int)> dfs2 = [&](int source, int parent, int val){

        ans[source] = val;     

    	for(auto x: adj[source]){
    		if(x == parent)
    			continue;

    		int temp = val - sz[x] + (n - sz[x]);
            dfs2(x, source, temp);
    	}
    };
    dfs2(0, -1, temp);


    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << "\n";

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