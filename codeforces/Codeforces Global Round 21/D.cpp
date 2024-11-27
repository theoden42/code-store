

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

struct SegTreeMin {
	struct node {
        //change code here
        int val;
        int ind;
	};

    //neutral element here
    node iden = {INF, -1}; 
	// fix these two functions
	node combine(node& a, node& b){
 		node t;
		if(a.val < b.val){
			t.val = a.val;
			t.ind = a.ind;
		}
		else{
			t.val = b.val;
			t.ind = b.ind;
		}
        
 		return t;
 	}
 	node single_value(int v, int in){
 		node t;
        // what to store in leaves corresponding to array value v
        t.val = v;
        t.ind = in;
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

	node get(int l, int r){
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

	node getUtil(int l, int r, int x, int lx, int rx){

		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
		node t1 = getUtil(l, r, 2 * x + 1, lx, m);
		node t2 = getUtil(l, r, 2 * x + 2, m, rx);
		return combine(t1, t2);
		
	}

	void setUtil(int ind, int val, int x, int lx, int rx){
		if(rx - lx == 1){
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


struct SegTreeMax {
	struct node {
        //change code here
        int val;
        int ind;
	};

    //neutral element here
    node iden = {0, -1}; 
	// fix these two functions
	node combine(node& a, node& b){
 		node t;
		if(a.val > b.val){
			t.val = a.val;
			t.ind = a.ind;
		}
		else{
			t.val = b.val;
			t.ind = b.ind;
		}
        
 		return t;
 	}
 	node single_value(int v, int in){
 		node t;
        // what to store in leaves corresponding to array value v
        t.val = v;
        t.ind = in;
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

	node get(int l, int r){
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

	node getUtil(int l, int r, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return arr[x];
		}
		else if(lx >= r || rx <= l){
			return iden;
		}
		int m = (lx + rx) / 2;
		node t1 = getUtil(l, r, 2 * x + 1, lx, m);
		node t2 = getUtil(l, r, 2 * x + 2, m, rx);
		return combine(t1, t2);
		
	}

	void setUtil(int ind, int val, int x, int lx, int rx){
		if(rx - lx == 1){
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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    if(n == 1){
    	cout << 0 << "\n";
    	return;
    }


    SegTreeMin stmn;
    SegTreeMax stmx;
    stmn.init(n);
    stmn.build(a);
    stmx.init(n);
    stmx.build(a);


    vector<int> greater(n), smaller(n);
    stack<pair<int,int>> mon;
    for(int i = n - 1; i >= 0; i--){
    	while(!mon.empty() && mon.top().first < a[i]){
    		mon.pop();
    	}
    	if(mon.empty()){
    		greater[i] = n;
    	}
    	else{
    		greater[i] = mon.top().second;
    	}
    	mon.push({a[i], i});	
    }

    mon = stack<pair<int,int>>();

    for(int i = n - 1; i >= 0; i--){
    	while(!mon.empty() && mon.top().first > a[i]){
    		mon.pop();
    	}
    	if(mon.empty()){
    		smaller[i] = n;
    	}
    	else{
    		smaller[i] = mon.top().second;
    	}
    	mon.push({a[i], i});	
    }

    int count = 0;
    int curr = 0;


    while(curr != n - 1){	

    	if(a[curr + 1] > a[curr]){
    		int mxindex = smaller[curr];
    		auto mx = stmx.get(curr + 1, mxindex);
    		curr = mx.ind;
    		count++;
    	}
    	else{
    		int mxindex = greater[curr];
    		auto mx = stmn.get(curr + 1, mxindex);
    		curr = mx.ind;
    		count++;
    	}
    }


    cout << count << "\n";
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}