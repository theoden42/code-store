

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> h(n + 1);
    for(int i = 1; i <= n; i++){
    	cin >> h[i];
    }
    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1), time(n + 1), in(n + 1);
    for(int i = 0; i < m; i++){
    	int a, b;
    	cin >> a >> b;
    	in[b] += 1;
    	adj[a].push_back(b);
    }
    for(int i = 1; i <= n; i++){
    	time[i] = h[i];
    }

    vector<int> topo;
    function<void(int)> topo_sort = [&](int v){
    	vis[v] = 1;
    	for(auto u: adj[v]){
    		if(!vis[u]){
    			topo_sort(u);
    		}
    	}
    	topo.push_back(v);
    };

    for(int i = 1; i <= n; i++){
    	if(!vis[i]){
    		topo_sort(i);
    	}
    	reverse(topo.begin(), topo.end());
	    for(auto x: topo){
	    	for(auto y: adj[x]){
	    		int nwtime = time[x] + ((h[y] >= h[x]) ? (h[y] - h[x]) : (k - h[x] + h[y]));
	    		// debug(x, y, nwtime);
	    		time[y] = max(time[y], nwtime);
	    	}
	    }
    	topo.clear();
    }

    vis.assign(n + 1, 0);
    vector<pair<int,int>> values;
    multiset<int> after;
    for(int i = 1; i <= n; i++){
    	if(in[i] == 0){
    		values.push_back({h[i], i});
    	}
    }

    sort(all(values));
    for(int i = 1; i <= n; i++){
    	after.insert(time[i]);
    }

    int ans = 1e18;

    function<void(int, int)> changedfs = [&](int source, int parent){
    	// vis[source] = 1;
    	after.erase(after.find(time[source]));
        // debug(time[source]);

    	if(parent == -1)
    		time[source] += k;
    	else { 
    		time[source] = max(time[source], time[parent] + ((h[source] >= h[parent]) ? (h[source] - h[parent]) : (k - h[source] + h[parent])));
    	}

    	after.insert(time[source]);

    	for(auto x: adj[source]){
    		changedfs(x, source);
    	}
    };

    for(int i = 0; i < values.size(); i++){
    	int hours = values[i].first;
    	int time = 0;
    	if(!after.empty()){
    		int temp = *after.rbegin() - hours;
    		time = max(time, temp);
    	}
    	ans = min(ans, time);

    	int j = i;
    	while(j < values.size() && values[j].first == values[i].first){	
    		j++;
    	}
    	for(int k = i; k < j; k++){
    		int vertex = values[k].second;
    		changedfs(vertex, -1);
    	}
        i = j - 1;
    }

    cout << ans << "\n";

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