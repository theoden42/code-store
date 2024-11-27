

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
    vector<int> b(n);
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    if(k == 1){
        int flag = 1;
        for(int i = 0; i < n; ++i){
            if(b[i] != i + 1){
                flag = 0;
                break;
            }
        }
        if(flag){
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }

    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n; i++){
    	adj[i + 1].push_back(b[i]);	
    }

    vector<int> vis(n + 1);
    vector<int> dist(n + 1);
    vector<int> cost(n + 1, -1);

    function<int(int, int)> checkcycle = [&](int source, int d){
    	if(cost[source] != -1)
    		return cost[source];

    	vis[source] = 1;
    	dist[source] = d;
    	for(auto x: adj[source]){
    		if(vis[x]){
                if(cost[x] != -1)
                    return cost[source] = cost[x];
    			int sz = abs(dist[source] - dist[x]) + 1;	
    			return cost[source] = sz;
    		} else {
    			int val = checkcycle(x, d + 1);
    			return cost[source] = val;
    		}
    	}
        return 0;
    };

    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		int sz = checkcycle(i, 0);
    		if(sz != k){
    			cout << "No\n";
    			return;	
    		}
    	}
    }

    cout << "Yes\n";
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