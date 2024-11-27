

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

    vector<int> perm;
    for(int i = 1; i <= n; i++)
    	perm.push_back(i);

    vector<int> parent(n + 1);
    function<void(int,int)> dfs = [&](int src, int pnt){
    	parent[src] = pnt;
    	for(auto x: adj[src]) if(x != pnt){
    		dfs(x, src);
    	}
    };

    if(n <= 2){
    	cout << "-1\n";
    	return;
    } else if(n <= 1000){
    	int flag = 0;
	    for(int cnt = 1; cnt <= 100; cnt++){
	    	shuffle(all(perm), rng);
	    	vector<int> magnets;
	    	for(int i = 1; i <= n; i++){
	    		magnets.push_back(i);
	    	}
	    	for(int i = 0; i < n; i++){
		    	dfs(perm[i], perm[i]);
		    	for(int j = 0; j < n; j++){
		    		magnets[j] = parent[magnets[j]];
		    	}
	    	}
	    	set<int> st;
	    	for(auto x: magnets)
	    		st.insert(x);
	    	if(st.size() > 1){
	    		flag = 1;
	    		for(auto x: perm){
	    			cout << x << " ";
	    		}
	    		cout << "\n";
	    		return;
	    	}
	    }	
	    cout << "-1\n";
    } else {
    	shuffle(all(perm), rng);
    	for(auto x: perm){
    		cout << x << " ";
    	}
    	cout << "\n";
    	return;
    }

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