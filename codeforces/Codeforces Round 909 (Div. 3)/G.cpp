

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
	T iden = vector<int>(0);
   
	T combine(T a, T b){
 	    T temp;	
 	    int i = 0;
 	    int j = 0;
 	    int n = a.size();
 	    int m = b.size();
 	    while(i < n && j < m){
 	    	if(a[i] <= b[j]){
 	    		temp.push_back(a[i]);
 	    		i++;
 	    	} else { 
 	    		temp.push_back(b[j]);
 	    		j++;
 	    	}
 	    }
 	    while(i < n){
 	    	temp.push_back(a[i]);
 	    	i++;
 	    }
 	    while(j < m){
 	    	temp.push_back(b[j]);
 	    	j++;
 	    }
 		return temp;
 	}
 	T single_value(int v){
    	T temp;
    	temp.push_back(v);
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

	int get(int l, int r, int k){
		return getUtil(l, r, k, 0, 0, sz);
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

	int getUtil(int l, int r, int k, int x, int lx, int rx){
		if(lx >= l && rx <= r){
			return (int)(lower_bound(arr[x].begin(), arr[x].end(), k) - arr[x].begin());
		} else if(lx >= r || rx <= l){
			return 0;
		}
		int m = (lx + rx) / 2;
        int left = getUtil(l, r, k, 2 * x + 1, lx, m);
		int right = getUtil(l, r, k, 2 * x + 2, m, rx);
		return left + right;
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
    vector<int> p(n);
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++){
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
    	cin >> p[i];
    }

   	vector<int> in_time(n + 1), out_time(n + 1);
   	int time = 0;
   	function<void(int, int)> dfs = [&](int source, int parent){
   		in_time[source] = time++;
   		for(auto x: adj[source]){
   			if(x == parent)
   				continue;
   			dfs(x, source);
   		}
   		out_time[source] = time++;
   	}; dfs(1, -1);

   	vector<int> times(n);
   	for(int i = 0; i < n; i++){
   		times[i] = in_time[p[i]];
   	}

   	SegTree<vector<int>> st;
   	st.init(n);
   	st.build(times);

   	for(int i = 0; i < q; i++){
    	int l, r, x;
    	cin >> l >> r >> x;
    	l--;
    	r--;
    	int count = st.get(l, r + 1, out_time[x]);
    	count -= st.get(l, r + 1, in_time[x]);

    	if(count > 0){
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";
    	}
    }

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