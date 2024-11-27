

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
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }


    vector<int> oddvis(n + 1, 0);
    vector<int> evenvis(n + 1, 0);
    vector<int> even(n + 1, 1e9);
    vector<int> odd(n + 1, 1e9);

    even[1] = 0;	
    evenvis[1] = 1;

    queue<int> oddnodes, evennodes;	
    evennodes.push(1);

    while(!oddnodes.empty() || !evennodes.empty()){
    	if(!oddnodes.empty()){
    		auto nd = oddnodes.front();
    		oddnodes.pop();
    		for(auto x: adj[nd]){
    			if(!evenvis[x]){
    				evenvis[x] = 1;
    				even[x] = min(even[x], odd[nd] + 1);
    				evennodes.push(x);
    			}
    		}
    	}
    	if(!evennodes.empty()){
    		auto nd = evennodes.front();
    		evennodes.pop();
    		for(auto x: adj[nd]){
    			if(!oddvis[x]){
    				oddvis[x] = 1;
    				odd[x] = min(odd[x], even[nd] + 1);
    				oddnodes.push(x);
    			}
    		}
    	}
    }

    debug(odd, even);

    int mn1 = 0, mn2 = 0;
    for(int i = 1; i <= n; i++){
    	mn1 = max(mn1, odd[i]);
    	mn2 = max(mn2, even[i]);
    }

    mn1 = min(mn1, mn2);
    if(mn1 == 1e9){
    	cout << "-1\n";
    } else {
    	cout << mn1 << "\n";
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