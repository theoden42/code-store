

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
	        int operation = 0;
		};

	    node iden = {0};
		node combineOperation(node& a, node& b){
	 		node t;
	        t.operation = a.operation + b.operation;
	 		return t;
	 	}
	 	node single_value(int v){
	 		node t;
	        t.operation = v;
	 		return t;
	 	}

c
	    
		int sz = 1;
		vector<node> arr;
		void init(int n){
			while(sz < n){
				sz *= 2;
			}
			arr.resize(2 * sz, iden);
		}

		int get(int ind){
			return (getUtil(ind, 0, 0, sz).operation);
		}

		void add(int l, int r, int v){
			addUtil(l, r, 0, 0, sz, v);
		}

		node getUtil(int ind, int x, int lx, int rx){
			if(rx - lx == 1){
				return arr[x];
			}

			int m = (lx + rx) / 2;
			if(ind < m){
				node t = getUtil(ind, 2 * x + 1, lx, m);
				return combineOperation(arr[x], t);
			}
			else{
				node t = getUtil(ind, 2 * x + 2, m, rx);
				return combineOperation(arr[x], t);
			}

		}

		void addUtil(int l, int r, int x, int lx, int rx, int v){
			propogate(x, lx, rx);
			if(lx >= r || rx <= l){
				return;
			}
			else if(lx >= l && rx <= r){
				node temp = {v};
				// debug(lx, rx, temp.operation);
				arr[x] = combineOperation(arr[x], temp);
				return; 
			}
			int m = (lx + rx) / 2;
			addUtil(l, r, 2 * x + 1, lx, m, v);
			addUtil(l, r, 2 * x + 2, m, rx, v);
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
	    		st.add(l, r, v);
	    	}
	    	else{
	    		int i;
	    		cin >> i;	
	    		cout << st.get(i) << "\n";
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