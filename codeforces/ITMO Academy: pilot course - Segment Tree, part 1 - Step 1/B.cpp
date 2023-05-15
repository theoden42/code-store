
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
	vector<int> arr;
	void init(int n){
		size = 1;
		while(size < n){
			size *= 2;
		}
		arr.assign(2 * size, INF);
	}
	void build(vector<int>& a){
		build(a, 0, 0, size);
	}
	void set(int index, int value){
		set(index, value, 0, 0, size);
	}
	int get(int l, int r){
		return get(l, r, 0, 0, size);
	}

	void build(vector<int>& a, int x, int lx, int rx){
		debug(x, lx, rx);
		if(rx - lx == 1){
			if(lx < (int)a.size()){
				arr[x] = a[lx];
			}
			return;
		}
		int m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = min(arr[2 * x + 1], arr[2 * x + 2]);
	}

	void set(int index, int value, int x, int lx, int rx){
		if(rx - lx == 1){
			arr[x] = value;
			return;
		}
		int m = (lx + rx) / 2;
		if(index < m){
			set(index, value, 2 * x + 1, lx, m);
		}else{
			set(index, value, 2 * x + 2, m, rx);
		}
		arr[x] = min(arr[2 * x + 1], arr[2 * x + 2]);
	}

	int get(int l, int r, int x, int lx, int rx){
		if(lx >= r || rx <= l)return INF;
		if(lx >= l && rx <= r)return arr[x];

		int mid = (lx + rx) / 2;
		int m1 = get(l, r, 2 * x + 1, lx, mid);
		int m2 = get(l, r, 2 * x + 2, mid, rx);

		return min(m1, m2);
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
    debug(st.arr);
    for(int i = 1; i <= m; i++){
    	int q, in, v;
    	cin >> q >> in >> v;
    	if(q == 1){
    		st.set(in, v);
    	}
    	else{
    		cout << st.get(in, v) << "\n";
    	}
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}