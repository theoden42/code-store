

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
    vector<int> b(n + 1);
    multiset<int> mst;

    for(int i = 1; i <= n; i++){
    	cin >> b[i];
    	mst.insert(b[i]);
    }

    int k;
    if(b[n] == n + 1){
    	k = n;
    }
    else if(b[1] == 0){
    	k = 0;
    }
    else{
    	int mn = n + 1;
	   	for(int i = 1; i < n; i++){
	    	mn = min(mn, b[i]);
	    	mst.erase(mst.find(b[i]));
	    	int mx = *(--mst.end());
	    	if(mn > i && mx <= i){
	    		k = i;
	    		break;
	    	}
	    }
    }

    cout << k << "\n";

    vector<vector<int>> adj(n + 1);
    vector<int> starts;
    for(int i = 1; i <= n; i++){
    	if(i <= k){
    		if(b[i] != n + 1){
    			adj[b[i]].push_back(i);
    		}
    		else{	
    			starts.push_back(i);
    		}
    	}
    	else{
    		if(b[i] != 0){
    			adj[b[i]].push_back(i);
    		}
    		else{
    			starts.push_back(i);
    		}
    	}
    }

   	int temp = 0;
    vector<int> ans;
    for(auto s: starts){
    	if(adj[s].size() == 0){
    		ans.push_back(s);
    	}
    	else{
    		temp = s;
    	}
    }

    function<void(int)> dfs = [&](int source)->void{
    	ans.push_back(source);
        int nw = 0;
    	for(auto x: adj[source]){
            if(adj[x].size() == 0){
                ans.push_back(x);
            }
            else{
                nw = x;
            }
    	}
        if(nw != 0)dfs(nw);
    };

	if(temp != 0)dfs(temp);

    for(auto a: ans){
    	cout << a << " ";
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