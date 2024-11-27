

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
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }

    map<int,int> deg;
    for(int i = 1; i <= n; i++){
    	deg[adj[i].size()]++;
    }

    if(deg.size() == 2){
    	int f = 0;
    	for(auto d: deg){
    		if(d.first != 1){
    			f = d.first;
    			break;
    		}
    	}
    	cout << f << " " << f - 1 << "\n";
    	return;
    }

    vector<int> ans(2);
    for(auto& x: deg){
    	if(x.second == 1){
    		ans[0] = x.first;
    	}
    }

    for(auto x: deg){
    	if(x.second == ans[0]){
    		ans[1] = x.first - 1;
    	}
    }

    cout << ans[0] << " " << ans[1] << "\n";
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