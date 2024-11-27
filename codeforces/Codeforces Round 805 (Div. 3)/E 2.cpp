

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


struct DSU{
	vector<int> parent;
	vector<int> sz;

	void init(int n){
		parent.resize(n + 1);
		sz.resize(n + 1);
		for(int i = 0; i <= n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}

	int getparent(int a){
		return parent[a] == a ? a : getparent(parent[a]);
	}

	void unite(int a, int b){
		int x = getparent(a);
		int y = getparent(b);

		if(x == y) return;

		if(sz[x] < sz[y]){
			sz[y] += sz[x];
			parent[x] = y;
		}
		else{
			sz[x] += sz[y];
			parent[y] = x;  
		}
	}

	bool check(){
		int n = parent.size();

		for(int i = 1; i < n; i++){
			int x = getparent(i);
			if(sz[x] & 1)return false;
		}
		return true;
	}
};


void solve() {
    int n;
    cin >> n;

    map<int,int> mp;

    DSU d;
    d.init(n);


    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	d.unite(a, b);
    	mp[a]++;
    	mp[b]++;

    }


    for(int i = 1; i <= n; i++){
    	if(mp[i] != 2){
    		cout << "No\n";
    		return;
    	}
    }


    if(d.check()){
    	cout << "Yes\n";
    }
    else{
    	cout << "No\n";
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