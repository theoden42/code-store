

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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    vector<int> sz(n + 1);
    multiset<pair<int,int>> mst;
    for(int i = 1; i <= n; i++){
    	mst.insert({adj[i].size(), i});
    	sz[i] = adj[i].size();
    }
    vector<int> removed(n + 1);
    int curr = 1;
    while(!mst.empty()){
    	auto it = mst.begin();
    	vector<int> nodes;
    	while(it != mst.end()){
    		if(it->first <= 1){
    			removed[curr] += 1;
    			for(auto x: adj[it->second]){
    				if(sz[x] > 1){
    					nodes.push_back(x);
    				}
    			}
    			sz[it->second] = 0;
    			mst.erase(it);
    			it = mst.begin();
    		} else {
    			break;
    		}
    	}
    	for(auto x: nodes){
    		mst.erase({sz[x], x});
    		sz[x] -= 1;
    		mst.insert({sz[x], x});
    	}
    	curr += 1;
    }

    int sum = 0;
    for(int i = 1; i <= k && i <= n; i++){
    	sum += removed[i];
    }
    cout << n - sum << "\n";
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