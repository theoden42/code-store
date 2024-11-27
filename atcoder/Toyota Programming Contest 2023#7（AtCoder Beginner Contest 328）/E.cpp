

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

struct dsu{
	vector<int> parent;
	vector<int> sz;

	void init(int n){
		parent.resize(n);
		sz.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}

	int getparent(int x){
		return parent[x] = (parent[x] == x ? x : getparent(parent[x])); 
	}

	int unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)
			return 0;

		if(sz[a] < sz[b])
			swap(a, b);

		parent[b] = a;
		sz[a] += sz[b];

		return 1;
	}

};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edges(m);
    for(int i = 0; i < m; i++){
    	int u, v, w;
    	cin >> u >> v >> w;
    	edges[i] = {u, v, w};
    }

    int mnvalue = k;
    function<void(int, int, vector<int>& curr)> recur 
    = [&](int num, int ind, vector<int> chosen){
    	if(num == n - 1){
    		int sum = 0;
    		for(auto ind: chosen){
    			sum += (edges[ind][2]);
    			sum %= k;
    		}
    		dsu d;
    		d.init(n);
    		int flag = 1;
    		for(auto ind: chosen){
    			flag &= d.unite(edges[ind][0] - 1, edges[ind][1] - 1);
    		}
    		if(flag){
    			mnvalue = min(mnvalue, sum);
    		}
    	} else {
    		for(int i = ind; i < m; i++){
    			chosen.push_back(i);
    			recur(num + 1, i + 1, chosen);
    			chosen.pop_back();
    		}
    	}
    };
    vector<int> temp;
    recur(0, 0, temp);

    cout << mnvalue << "\n";
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