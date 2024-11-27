

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
    int n, m;
    cin >> n >> m;
    map<pair<int,int>,int> mp;
    vector<vector<int>> adj(n + 1);

    map<int,int> company2;

    for(int i = 1; i <= m; i++){
    	int u, v;
    	cin >> u >> v;
    	mp[{u, v}] = i;
    	mp[{v, u}] = i;
    	adj[v].push_back(u);
    	adj[u].push_back(v);
    }

    debug(adj);
    int source = -1;

    for(int i = 1; i <= n; i++){
    	if(adj[i].size() < n - 1){
    		source = i;
    		break;
    	}
    }

    if(source == -1){

    	for(int x: adj[1]){
    		int r = mp[{x, 1}];
    		company2[r] = 2;
    	}
    	for(auto& x: company2){
    		x.second = 3;
    		break;
    	}

    	cout << "3\n";
    	for(int i = 1; i <= m; i++){
    		if(company2[i] != 0){
    			cout << company2[i] << " ";
    		}
    		else{
    			cout << 1 << " ";
    		}
    	}

    	cout << "\n";

		return;
    }

    for(int x: adj[source]){
    	int r = mp[{x, source}];
    	company2[r] = 1;
    }

    cout << 2 << "\n";
    for(int i = 1; i <= m; i++){
    	if(company2[i] == 1){
    		cout << 2 << " ";
    	}
    	else{
    		cout << 1 << " ";
    	}
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