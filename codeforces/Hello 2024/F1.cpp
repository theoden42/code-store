

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

#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

template<typename T, typename U>
struct LSegTree {
    int sz = 1;
    vector<T> arr;
    vector<U> updates;
    T iden = -INF; // define the identity element here
    U iden_upd = 0; // define the identity update here
   
    T combine(T a, T b){
        // define how to combine two nodes
    	T temp = max(a, b);
        return temp;
    }

    T single_value(int v){
        // what to store in leaves corresponding to array value v
        T temp = v;
        return temp;
    }

    T apply_update(T node, U update, int tl, int tr) { 
        // define how to apply update to a node, with endpoints tl and tr
    	node += update;
    	return node;
    }

    U combine_update(U old_upd, U new_upd, int tl, int tr) { 
        // define how to combine update into one, with endpoints tl and tr
        old_upd += new_upd;
        return old_upd;
    }

    void init(int n){
        while(sz < n){
            sz *= 2;
        }
        arr.resize(2 * sz, iden);
        updates.resize(2 * sz, iden_upd);
    }

    void propogate(int x, int lx, int rx) { 
        if(updates[x] == iden_upd) { 
            return;
        }
        arr[x] = apply_update(arr[x], updates[x], lx, rx);
        if(2 * x + 2 < 2 * sz) { 
            int m = (lx + rx) / 2;
            updates[2 * x + 1] = combine_update(updates[2 * x + 1], updates[x], lx, m);
            updates[2 * x + 2] = combine_update(updates[2 * x + 2], updates[x], m, rx);
        }
        updates[x] = iden_upd;
    }

    void build(vector<int>& a){
        build(a, 0, 0, sz);
    }

    void update(int l, int r, U upd){
        updateUtil(l, r, upd, 0, 0, sz);
    }

    T get(int l, int r){
        return getUtil(l, r, 0, 0, sz);
    }

    T getpos(){
    	return getposutil(0, 0, sz);
    }

    T getposutil(int x, int lx, int rx){
    	propogate(x, lx, rx);
    	if(rx - lx == 1){
    		if(arr[x] >= 0)
    			return lx;
    		else 
    			return -1;
    	}
    	int val = arr[2 * x + 2];
    	int md = (rx + lx) / 2;
    	if(val >= 0){
    		return getposutil(2 * x + 2, md, rx);
    	} else {
    		return getposutil(2 * x + 1, lx, md);
    	}
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
        propogate(x, lx, rx);
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

    void updateUtil(int l, int r, U upd, int x, int lx, int rx){
        propogate(x, lx, rx);
        if(lx >= r || l >= rx)
            return;

        if(lx >= l && rx <= r) {
            updates[x] = combine_update(updates[x], upd, lx, rx);
            propogate(x, lx, rx);
            return;
        }
        
        int m = (lx + rx) / 2;
        updateUtil(l, r, upd, 2 * x + 1, lx, m);
        updateUtil(l, r, upd, 2 * x + 2, m, rx);
        arr[x] = combine(arr[2 * x + 1], arr[2 * x + 2]);
    }
};


template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = 0ll; // define the identity element here
   
	T combine(T a, T b){
 	    T temp = a + b;	
 		return temp ;
 	}
 	T single_value(int v){
    	T temp;
 		return temp = v;
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
    vector<int> a(n), b(n), c(n - 1);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++){
    	cin >> c[i];
    }
    vector<int> prefix(n);
    vector<int> prefix2(n);
    prefix[n - 1] = a[n - 1];
    prefix2[n - 1] = b[n - 1];
    for(int i = n - 2; i >= 0; i--){
    	prefix[i] += prefix[i + 1];
    	prefix[i] += a[i];
    	prefix2[i] += prefix2[i + 1];
    	prefix2[i] += b[i];	
    }

    vector<int> diff(n);
    for(int i = 0; i < n; i++){
    	diff[i] = prefix[i] - prefix2[i];
    }
    // debug(diff);
    LSegTree<int,int> lst;
    SegTree<int> sta, stb;
    lst.init(n);
    lst.build(diff);

    sta.init(n);
    stb.init(n);
    sta.build(a);
    stb.build(b);

    // debug(lst.arr);


    for(int i = 1; i <= q; i++){
    	int p, x, y, z;
    	cin >> p >> x >> y >> z;
    	p -= 1;

    	int d1 = a[p] - x;
    	lst.update(0, p + 1, -d1);
    	a[p] = x;
    	int d2 = b[p] - y;
    	lst.update(0, p + 1, d2);
    	b[p] = y;

    	sta.set(p, x);
    	stb.set(p, y);

    	debug(lst.arr);

    	int ans = 0;   
        ans += sta.get(0, n);
        ans -= max(0ll, lst.get(0, n));

    	cout << ans << "\n";
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