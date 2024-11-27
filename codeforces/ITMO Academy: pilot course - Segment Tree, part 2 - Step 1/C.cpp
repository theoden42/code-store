

/* author: (g)theoden42 */


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
        //change code here
        int operation;
	};

    //neutral element here
    node iden = {LLONG_MAX}; 
	// fix these two functions
	node combineOperation(node& a, node& b){
 		node t;
        // how to combine two nodes
 		if(b.operation == LLONG_MAX)t.operation = a.operation;
 		else t.operation = b.operation;

 		return t;
 	}
 	node single_value(int v){
 		node t;
        // what to store in leaves corresponding to array value v
        t.operation = v;
 		return t;
 	}
    
	int sz = 1;
	vector<node> arr;
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, {0});
	}

	void apply_operation(node &a, node b){
 		a = combineOperation(a, b);
 	}

 	void propogate(int x, int lx, int rx){
 		if(rx - lx == 1)return;
 		apply_operation(arr[2 * x + 1], arr[x]);
 		apply_operation(arr[2 * x + 2], arr[x]);
 		arr[x] = {LLONG_MAX};
 	}


	void update(int l, int r, int v){
		updateUtil(l, r, 0, 0, sz, v);
	}

	int getPoint(int ind){
		return ((getPointUtil(ind, 0, 0, sz)).operation);
	}

	// void build(vector<int>& a, int x, int lx, int rx){
	// 	if(rx - lx == 1){
	// 		if(lx < a.size()){
	// 			arr[x] = single_value(a[lx]);
	// 		}	
	// 		return;
	// 	}
	// 	int m = (lx + rx) / 2;
	// 	build(a, 2 * x + 1, lx, m);
	// 	build(a, 2 * x + 2, m, rx);
	// 	arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	// }

	// node getUtil(int l, int r, int x, int lx, int rx){
	// 	if(lx >= l && rx <= r){
	// 		return arr[x];
	// 	}
	// 	else if(lx >= r || rx <= l){
	// 		return iden;
	// 	}
	// 	int m = (lx + rx) / 2;
	// 	getUtil(l, r, 2 * x + 1, lx, m);
	// 	getUtil(l, r, 2 * x + 2, m, rx);
	// 	return combine(arr[2 * x + 1], arr[2 * x + 2]);
		
	// }

	// void setUtil(int ind, int val, int x, int lx, int rx){
	// 	if(rx - lx == 1){
	// 		arr[x] = single_value(val);
	// 		return;
	// 	}

	// 	int m = (lx + rx) / 2;
	// 	if(ind < m){
	// 		setUtil(ind, val, 2 * x + 1, lx, m);
	// 	}
	// 	else{
	// 		setUtil(ind, val, 2 * x + 2, m, rx);
	// 	}

	// 	arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
	// }

	void updateUtil(int l, int r, int x, int lx, int rx, int v){

		propogate(x, lx, rx);
		if( lx >= r || rx <= l){
			return;
		}
		else if(lx >= l && rx <= r){
			node t = {v};
			arr[x] = combineOperation(arr[x], t);
			debug(arr[x].operation);
			return;
		}


		int m = (lx + rx) / 2;
		updateUtil(l, r, 2 * x + 1, lx, m, v);
		updateUtil(l, r, 2 * x + 2, m, rx, v);
	}

	node getPointUtil(int ind, int x, int lx, int rx){
		propogate(x, lx, rx);
		if(rx - lx == 1){
			return arr[x];
		}
		int m = (lx + rx) / 2;
		node rem;
		if(ind < m){
			rem = getPointUtil(ind, 2 * x + 1, lx, m);
		}
		else{
			rem = getPointUtil(ind, 2 * x + 2, m, rx);
		}	
		return rem;
	}

};



void solve() {
    int n, m;
    cin >> n >> m;
    SegTree st;
    st.init(n);


    for(int i = 1; i <= m; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int l, r, v;
    		cin >> l >> r >> v;
    		// debug(l, r, v);
    		st.update(l, r, v);

    		// for(auto x: st.arr){
    		// 	cout << x.operation << " ";
    		// }
    		// cout << "\n";
    	}
    	else{
    		int i;
    		cin >> i;
    		cout << st.getPoint(i) << "\n";

    		// for(auto x: st.arr){
    		// 	cout << x.operation << " ";
    		// }
    		// cout << "\n";
    	}
    }
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //wcin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}