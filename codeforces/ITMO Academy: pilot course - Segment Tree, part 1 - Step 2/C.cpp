

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


struct SegTree {
	struct node {
        //change code here
        int max;
	};

    //neutral element here
    node iden = {0};
	// fix these two functions
	node combine(node& a, node& b){
 		node t;
        // how to combine two nodes
        t.max = max(a.max, b.max);
 		return t;
 	}
 	node single_value(int v){
 		node t;
        // what to store in leaves corresponding to array value v
        t.max = v;
 		return t;
 	}
    
	int sz = 1;
	vector<node> arr;
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

	int get(int k){
		return getUtil(k, 0, 0, sz);
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

	int getUtil(int k, int x, int lx, int rx){
		if(rx - lx == 1){
			if(arr[x].max >= k){
				return lx;
			}
			else{
				return -1;
			}
		}
		int left = arr[2 * x + 1].max;
		int m = (lx + rx) / 2;
		if(left >= k){
			return getUtil(k, 2 * x + 1, lx, m);
		}
		else{
			return getUtil(k, 2 * x + 2, m, rx);		
		}

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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    SegTree st;
    st.init(n);
    st.build(a);
    for(int i = 1; i <= m; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int i, v;
    		cin >> i >> v;
    		st.set(i, v);
    	}
    	else{
    		int x;
    		cin >> x;
    		cout << st.get(x) << "\n";
    	}
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