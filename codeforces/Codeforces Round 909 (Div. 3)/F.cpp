

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
    int n, q;
    cin >> n >> q;
    vector<int> d(q + 1);
    for(int i = 1; i <= q; i++){
    	cin >> d[i];
    }

    vector<vector<int>> adj(n + 1);

    int root = 1;
    int t_child = -1;

    adj[1].push_back(2);
    cout << 1 << " " << 2 << "\n";
    adj[1].push_back(3);
    cout << 1 << " " << 3 << "\n";
    for(int i = 4; i <= n; i++){
    	adj[i - 1].push_back(i);
    	cout << i - 1 << " " << i << "\n";
    }

    int curr_height = n - 1;
    for(int i = 1; i <= q; i++){
    	// debug(d[i], adj);
    	if(d[i] == curr_height){
    		cout << "-1 -1 -1\n";
    		continue;
    	} else if(d[i] < curr_height){
    		int remove = curr_height - d[i];
    		int node = t_child;
    		int last_vertex = 1;
    		while(node != -1){
    			if(adj[node].empty())
    				break;
    			node = adj[node][0];	
    		}
    		if(node == -1){
    			last_vertex = 1;
    		} else {
    			last_vertex = node;
    		}
    		int parent = 1;
    		node = 3;
    		for(int j = 1; j < d[i]; j++){
    			parent = node;
    			node = adj[node][0];
    		}
    		adj[parent].erase(find(all(adj[parent]), node));
    		adj[last_vertex].push_back(node);
    		if(t_child == -1){
    			t_child = node;
    		}
    		curr_height = d[i];

    		cout << node << " " << parent << " " << last_vertex << "\n";

    	} else {
    		int to_add = d[i] - curr_height;
    		int last_vertex;
    		int node = 3;
    		while(true){
    			if(adj[node].empty())
    				break;
    			node = adj[node][0];
    		}
    		last_vertex = node;

    		node = t_child;
    		int parent = 1;
    		for(int j = 1; j <= n - 1 - d[i]; j++){
    			parent = node;
    			node = adj[node][0];
    		}
    		if(parent == 1){
    			t_child = -1;
    		}
    		adj[parent].erase(find(all(adj[parent]), node));
    		adj[last_vertex].push_back(node);
    		curr_height = d[i];
    		cout << node << " " << parent << " " << last_vertex << "\n";
    	}
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