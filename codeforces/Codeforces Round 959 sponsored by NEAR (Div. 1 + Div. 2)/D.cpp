

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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    cout << "YES\n";
    dsu d;
    d.init(n);
    vector<pair<int,int>> ans;
    for(int i = n - 1; i >= 1; i--){
    	vector<set<int>> rem(i);
    	for(int j = 0; j < n; j++){
    		rem[a[d.getparent(j)] % i].insert(d.getparent(j));
    	}
    	for(int j = 0; j < i; j++){
    		if(rem[j].size() >= 2){
    			int a = *rem[j].begin();
    			int b = *(--(rem[j].end()));
    			ans.push_back({a, b});
    			d.unite(a, b);
    			break;
    		}
    	}
    }
    reverse(all(ans));
    for(auto [a, b]: ans){
    	cout << a + 1 << " " << b + 1 << "\n";
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