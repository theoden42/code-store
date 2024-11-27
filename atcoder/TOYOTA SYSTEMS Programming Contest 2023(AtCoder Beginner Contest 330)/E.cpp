

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
    T iden = {0, 1e9}; // define the identity element here
   
	T combine(T a, T b){
 	    T temp;	
 	    temp.first = a.first + b.first;
 	    temp.second = min(a.second, b.second);
 		return temp;
 	}
 	T single_value(int v, int index){
    	T temp;
        temp.first = v;
        if(v == 0){
        	temp.second = index;
        } else {
        	temp.second = 1e9;
        }
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
				arr[x] = single_value(a[lx], lx);
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
			debug(val, lx);
			arr[x] = single_value(val, lx);
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
    vector<int> a(n);
    vector<int> freq(n + 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	if(a[i] <= n){
    		freq[a[i]] += 1;
    	}
    }

    SegTree<pair<int,int>> st;
    st.init(n + 1);
    st.build(freq);

    for(int t = 1; t <= q; t++){
    	int i, x;
    	cin >> i >> x;
    	i--;
    	if(a[i] <= n){
    		auto [in, _] = st.get(a[i], a[i] + 1);
    		st.set(a[i], in - 1);
    	} 
    	if(x <= n){
    		auto [in, _] = st.get(x, x + 1);
    		st.set(x, in + 1);
    	}
    	a[i] = x;
    	auto [sum, ind] = st.get(0, n + 2);
    	cout << ind << "\n";
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