

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

struct DSU {
	vector<int> parent;
	vector<int> sz;
	vector<set<int>> comps;

	DSU(int n){
		parent.resize(n);
		sz.resize(n);
		comps.resize(n, set<int>());
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sz[i] = 1;
			comps[i].insert(i);
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)
			return 1;

		if(sz[a] < sz[b])
			swap(a, b);
		for(auto x: comps[b]){
			comps[a].insert(x);
		}
		comps[b].clear();
		parent[b] = a;
		sz[a] += sz[b];
		return 0;
	}

	int klarge(int u, int k){
		int p = getparent(u);
		if(k > comps[p].size())
			return -1;
		vector<int> vals;
		for(int i = 0; i < k; i++){
			vals.push_back(*prev(comps[p].end()));
			comps[p].erase(prev(comps[p].end()));
		}
		for(auto x: vals){
			comps[p].insert(x);
		}
		return vals.back() + 1;
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    DSU d(n);

    for(int i = 1; i <= q; i++){
    	int t, u, v;
    	cin >> t >> u >> v;
    	if(t == 1){
    		u--;
    		v--;
    		d.unite(u, v);
    	} else {
    		u--;
    		int ans = d.klarge(u, v);
    		cout << ans << "\n";
    	}
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}