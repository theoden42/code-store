

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

const int p = 31;

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

template<typename T>
struct SegTree {

	int sz = 1;
	vector<T> arr;
    T iden = {0, 0, 0}; // define the identity element here
   
	T combine(T a, T b){
		T temp(3);
 	    int right = (b[0] * binpow(31, a[2])) % MOD;
 	    int left = (a[1] * binpow(31, b[2])) % MOD;

 	    temp[0] = a[0] + right;
 	    temp[0] %= MOD;
 	    temp[1] = b[1] + left;
 	    temp[1] %= MOD;
 	    temp[2] = a[2] + b[2];
 		return temp;
 	}

 	T single_value(int v){
    	T temp;
        temp = {v, v, 1};
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
  	string s;
  	cin >> s;
  	SegTree<vector<int>> st;
  	st.init(n);
  	vector<int> v(n);
  	for(int i = 0; i < n; i++){
  		v[i] = s[i] - 'a' + 1;
  	}
  	st.build(v);

  	for(int i = 1; i <= q; i++){
  		// debug(st.arr);
  		int t;
  		cin >> t;
  		if(t == 1){
  			int x;
  			char c;
  			cin >> x >> c;
  			st.set(x - 1, c - 'a' + 1);
  		} else{
  			int l, r;
  			cin >> l >> r;
  			l -= 1;
  			r -= 1;
  			auto vp = st.get(l, r + 1);
  			if(vp[0] == vp[1]){
  				cout << "Yes\n";
  			} else {
  				cout << "No\n";
  			}
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