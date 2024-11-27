

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

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = 0; // define the identity element here
   
	T combine(T a, T b, int num){
 	    T temp;	
        // how to combine two nodes
        int x = ceil(log2(sz));
        if(((num + 1) & 1) == (x & 1))
        	temp = (a | b);
        else 
        	temp = (a ^ b);

 		return temp;
 	}
 	T single_value(int v){
 		return v;
 	}
    
	void init(int n){
		while(sz < n){
			sz *= 2;
		}
		arr.resize(2 * sz, iden);
	}

	void build(vector<int>& a){
		build(a, 0, 0, sz, 0);
	}

	void set(int ind, int value){
		setUtil(ind, value, 0, 0, sz, 0);
	}

	T get(int l, int r){
		return getUtil(l, r, 0, 0, sz, 0);
	}

	void build(vector<int>& a, int x, int lx, int rx, int turn){
		if(rx - lx == 1){
			if(lx < a.size()){
				arr[x] = single_value(a[lx]);
				debug(arr[x], a[lx]);
			}	
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m, turn + 1);
		build(a, 2 * x + 2, m, rx, turn + 1);
		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2], turn);
	}

	T getUtil(int l, int r, int x, int lx, int rx, int turn){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
        T left = getUtil(l, r, 2 * x + 1, lx, m, turn + 1);
		T right = getUtil(l, r, 2 * x + 2, m, rx, turn + 1);
		return combine(left, right, turn);
	}

	void setUtil(int ind, int val, int x, int lx, int rx, int turn){
		if(rx - lx == 1){
			arr[x] = single_value(val);
			return;
		}

		int m = (lx + rx) / 2;
		if(ind < m){
			setUtil(ind, val, 2 * x + 1, lx, m, turn + 1);
		}
		else{
			setUtil(ind, val, 2 * x + 2, m, rx, turn + 1);
		}

		arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2], turn);
	}
};



void solve() {
    int n, m;
    cin >> n >> m;
    int sz = (1 << n);
	vector<int> v(sz);
	for(int i = 0; i < sz; i++){
		cin >> v[i];
	}

	SegTree<int> st;
	st.init(sz);
	st.build(v);

	debug(st.arr);

	for(int i = 0; i < m; ++i){
		int ind;
		int b;
		cin >> ind >> b;
		st.set(ind - 1, b);
		cout << st.get(0, sz)<< "\n";
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