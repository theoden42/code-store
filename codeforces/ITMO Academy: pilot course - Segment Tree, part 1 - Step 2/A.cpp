

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


struct SegTree {
	struct node {
		int sum;
		int pref;
		int suff;
		int max_seg;
	};

	// fix these two functions
	node combine(node& a, node& b){
 		node t;
 		t.sum = a.sum + b.sum;
 		t.pref = max(a.pref, a.sum + b.pref);
 		t.suff = max(b.suff, b.sum + a.suff);
 		t.max_seg = max({a.max_seg, b.max_seg, a.suff + b.pref});
 		return t;
 	}

 	node single_value(int v){
 		node t;
 		t.sum = v;
 		t.pref = (v > 0) ? v : 0;
 		t.suff = (v > 0) ? v : 0;
 		t.max_seg = (v > 0) ? v : 0;
 		return t;
 	}

	int sz = 1;
	node iden;
	vector<node> arr;
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		//initialise the identity element
		iden = {0, 0, 0, 0};
		arr.resize(2 * sz, iden);
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz);
	}

	void set(int ind, int value){
		setUtil(ind, value, 0, 0, sz);
	}

	node get(int l, int r){
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

	node getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
		return combine(arr[2 * x + 1], arr[2 * x + 2]);
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
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    SegTree st;
    st.init(n);
    st.build(a);
    int v = st.get(0, n).max_seg;

    cout << v << "\n";
    for(int i = 1; i <= m; i++){
    	int x, v;
    	cin >> x >> v;
    	st.set(x, v);

    	int r = st.get(0, n).max_seg;
    	cout << r << "\n";
    }

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}