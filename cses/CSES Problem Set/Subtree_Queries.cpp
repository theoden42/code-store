

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

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = 0; // define the identity element here
   
	T combine(T a, T b){
 	    T temp;	
 	    temp = a + b;
 		return temp ;
 	}
 	T single_value(int v){
    	T temp;
    	temp = v;
 		return temp;
 	}
    
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, iden);
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind, int value){
		setUtil(ind, value, 0, 0, sz);
	}

	T get(int l, int r){
		return getUtil(l, r, 0, 0, sz);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx]);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}

	T getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
        T left = getUtil(l, r, 2 * x + 1, lx, m);
		T right = getUtil(l, r, 2 * x + 2, m, rx);
		return combine(left, right);
	}

	void setUtil(int ind, int val, int x, int lx, int rx){
		if(rx - lx == 1){
			arr[x] = single_value(val);
			return;
		}

		int m = (lx + rx) / 2;
		if(ind < m){
			setUtil(ind, val, 2 * x + 1, lx, m);
		}
		else{
			setUtil(ind, val, 2 * x + 2, m, rx);
		}

		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	}
};



void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	for(int i = 0; i < n; i++){
		cin >> v[i];
	}

	vector<vector<int>> adj(n);
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--;v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> entrylabel(n), exitlabel(n);
	int count = 0;
	function<void(int,int)> dfs = [&](int source, int parent){
		entrylabel[source] = count;
		for(auto x: adj[source]){
			if(x == parent)
				continue;
			++count;
			dfs(x, source);
		}
		exitlabel[source] = count;
	}; dfs(0, -1);

	vector<int> temp(n);
	for(int i = 0; i < n; i++){
		temp[entrylabel[i]] = v[i];
	}

	// debug(entrylabel, exitlabel);

	SegTree<int> st;
	st.init(n);
	st.build(temp);

	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;
		if(t == 1){ 
			int s, x;
			cin >> s >> x;
			s--;
			st.set(entrylabel[s], x);
		} else {
			int ind = 0;
			cin >> ind;
			ind--;
			cout << st.get(entrylabel[ind], exitlabel[ind] + 1) << "\n";
		}
	}

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