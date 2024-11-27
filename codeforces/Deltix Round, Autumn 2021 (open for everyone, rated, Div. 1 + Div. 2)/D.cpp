

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
		if(parent[x] == x)
			return x;
		return parent[x] = getparent(parent[x]);
	}
	void unite(int a, int b){
		a = getparent(a);
		b = getparent(b);
		if(a == b)return;
		if(sz[a] < sz[b])
			swap(a, b);
		parent[b] = a;
		sz[a] += sz[b];
		sz[b] = 0;
	}
	void unitebest(){
		int n = sz.size();
		set<pair<int,int>> st;
		for(int i = 0; i < n; i++){
			st.insert({sz[getparent(i)], getparent(i)});
			if(st.size() >= 3)
				st.erase(st.begin());
		}
		if(st.size() < 2)
			return;
		auto it = --st.end();
		auto it2 = --(--st.end());
		unite(it->second, it2->second);
	}

	int maxsize(){
		int n = sz.size();
		int mx = 0;
		for(int i = 0; i < n; i++){
			// debug(mx, getparent(i));
			mx = max(mx, sz[getparent(i)]);
		}
		return mx;
	}
};

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> ans(n);
    vector<int> x(d), y(d); 

    for(int i = 0; i < d; i++){
    	cin >> x[i] >> y[i];
    	x[i]--;y[i]--;
    }
    dsu ds;
    ds.init(n);
    int count = 0;
    for(int i = 0; i < d; i++){
		if(ds.getparent(x[i]) == ds.getparent(y[i])) {
			count += 1;
		}
		else {
			ds.unite(x[i], y[i]);
		}
		vector<int> maxsizes;
		for(int i = 0; i < n; i++){
			if(ds.sz[i] != 0){
				maxsizes.push_back(ds.sz[i]);
			}
		}

		sort(all(maxsizes));
		int sum = 0;
		for(int i = maxsizes.size() - 1; (i >= maxsizes.size() - 1 - count) && i >= 0; i--){
			sum += maxsizes[i];
		}

    	cout << sum - 1 << "\n";
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}