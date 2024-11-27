

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
        // how to combine two nodes
        temp = a + b;
 		return temp ;
 	}
 	T single_value(int v){
    	T temp = v;
        // what to store in leaves corresponding to array value v
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    	cin >> a[i];

    vector<int> count(m);
    SegTree<int> st;
    st.init(m);
    st.build(count);
    int tmod = 0;
    int ans = 0;
    int curr = 0;

    auto get = [&](int l, int r){
    	if(l <= r)
    		return st.get(l, r + 1);
    	else {
    		return st.get(0, r + 1) + st.get(l, m);
    	}

    };

    for(int i = 0; i < n; i++){
    	int r = a[i] % m;
    	int sumleft 
    	= get((m - tmod) % m, (m - r - 1 - tmod + m) % m);
    	curr += r * sumleft;

    	int sumright 
    	= get(
    		(m - r - tmod + m) % m, (2 * m - 1 - tmod) % m);
    	curr -= ((m - r) % m) * sumright;

    	// debug((m - r - tmod + m) % m, (2 * m - 1 - tmod) % m, sumright);

    	tmod += r;
    	tmod %= m;

    	curr += r;
    	count[(r - tmod + m) % m] += 1;
    	st.set((r - tmod + m) % m, count[(r - tmod + m) % m]);
    	ans += curr;
    	// debug(count, curr);
    }

    cout << ans << "\n";
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