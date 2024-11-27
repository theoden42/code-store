

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

vector<vector<pair<int,int>>> adj;

struct dsu{
	vector<int> parent;
	vector<int> parent_dist;
	vector<vector<int>> childs;
	vector<int> sz;

	void init(int n){
		parent.resize(n);
		sz.resize(n);
		childs.resize(n);
		parent_dist.resize(n);
		adj.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sz[i] = 1;
			parent_dist[i] = 0;
			childs[i].push_back(i);	
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b, int d){
		int pa = getparent(a);
		int pb = getparent(b);
		if(pa == pb){
			if(parent_dist[a] + d == parent_dist[b])
				return 1;
			else 
				return 0;
		} else {
			unordered_set<int> vis;
			function<void(int, int)> dfs 
			= [&](int source, int dist){
				debug(source);
				vis.insert(source);
				parent_dist[source] = dist;
				for(auto x: adj[source]){
					if(vis.find(x.first) != vis.end())
						continue;
					dfs(x.first, dist + x.second);
				}
			};
			if(sz[pa] < sz[pb]){
				parent[pa] = pb;
				sz[pb] += sz[pa];
				for(auto x: childs[pa]){
					childs[pb].push_back(x);
				}
				sz[pa] = 0;
				childs[pa].clear();
				dfs(a, parent_dist[b] - d);
			} else {
				parent[pb] = pa;
				sz[pa] += sz[pb];
				for(auto x: childs[pb]){
					childs[pa].push_back(x);
				}
				sz[pb] = 0;
				childs[pb].clear();
				dfs(b, parent_dist[a] + d);
			}
			return 1;
		}
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> ans;
    adj.resize(n);
    dsu ds;
    ds.init(n);
    for(int i = 1; i <= q; i++){
    	int a, b, d;
    	cin >> a >> b >> d;
    	a--;
    	b--;
    	int val = ds.unite(b, a, d);
    	if(val){
    		ans.push_back(i);
    		adj[b].push_back({a, d});
    		adj[a].push_back({b, -d});
    	}
    }

    for(auto a: ans){
    	cout << a << " ";
    }
    cout << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}