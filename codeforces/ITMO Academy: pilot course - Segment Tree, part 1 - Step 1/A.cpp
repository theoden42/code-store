
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

struct segTree{
	int size;
	vector<ll> sums;
	void init(int n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		sums.assign(2 * size, 0LL);
	}


	void set(int index, int value){
		// set value at index to value 
		set(index, value, 0, 0, size);
	}
	long long get(int l, int r){
		// get between l and r - 1;
		return get(l, r, 0, 0, size);

	}

	void build(vector<int>& a){
		build(a, 0, 0, size);
	}


	void build(vector<int>& a, int x, int lx, int rx){
		debug(x, rx, lx);
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				sums[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}


	void set(int index, int value, int node, int lx, int rx){
		if(rx - lx == 1){
			sums[node] = value;
			return;
		}
		int mid = (lx + rx) / 2;
		if(index < mid){
			set(index, value, 2 * node + 1, lx, mid);
		} else{
			set(index, value, 2 * node + 2, mid, rx);
		}
		sums[node] = sums[2 * node + 1] + sums[2 * node + 2];
	}
	long long get(int l, int r, int node, int lx, int rx){


		if(rx <= l || lx >= r)return 0;

		if(lx >= l && rx <= r)return sums[node];

		int mid = (lx + rx) / 2;

		ll s1 = get(l, r, 2 * node + 1, lx , mid);
		ll s2 = get(l, r, 2 * node + 2, mid, rx);

		return s1 + s2;
	}
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    segTree st;
    st.init(n);
    st.build(ele);




    for(int i = 0; i < m; i++){
    	int t;
    	cin >> t;
    	if(t == 1){
    		int i, v;
    		cin >> i >> v;
    		st.set(i, v);
    	} else{
    		int l, r;
    		cin >> l >> r;
    		cout << st.get(l, r) << "\n" ;

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