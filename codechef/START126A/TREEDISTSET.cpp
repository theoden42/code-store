

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
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    vector<int> level(n + 1);
    function<void(int,int,int)> dfs 
    = [&](int source, int parent, int lev){
    	level[source] = lev;
    	for(auto x: adj[source]) if(x != parent){
    		dfs(x, source, lev + 1);
    	}
    }; dfs(1, -1, 0);


    int mx = 1;
    int mxd = 0;
    for(int i = 1; i <= n; i++){
    	if(level[i] > mxd){
    		mxd = level[i];
    		mx = i;
    	}
    }

    vector<int> level2(n + 1);

    function<void(int,int,int)> dfs2 
    = [&](int source, int parent, int lev){
    	level2[source] = lev;
    	for(auto x: adj[source]) if(x != parent){
    		dfs2(x, source, lev + 1);
    	}
    }; dfs2(mx, -1, 0);


    int mx2 = mx;
    int mxd2 = 0;
    for(int i = 1; i <= n; i++){
    	if(level2[i] > mxd2){
    		mxd2 = level2[i];
    		mx2 = i;
    	}
    }

    vector<int> paths;
    function<int(int,int)> findpath
    = [&](int source, int parent){
    	paths.push_back(source);
    	if(source == mx2)
    		return 1;

    	for(auto x: adj[source]) if(x != parent){
    		if(findpath(x, source))
    			return 1;
    	}

    	paths.pop_back();
    	return 0;
    };
    findpath(mx, -1);

    set<int> st;
    int count = 0;
    vector<char> ans(n + 1);

    for(auto x: paths){
    	if(count < paths.size() / 2){
    		ans[x] = 'R';
    	} else {
    		ans[x] = 'B';
    	}
    	count += 1;
    	st.insert(x);
    }



    count = 0;
    for(int i = 1; i <= n; i++){
    	if(st.find(i) == st.end()){
    		ans[i] = ((count & 1) ? 'B' : 'R');
    		count += 1;
    	}
    }

    for(int i = 1; i <= n; i++){
    	cout << ans[i];
    }
    cout << "\n";

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