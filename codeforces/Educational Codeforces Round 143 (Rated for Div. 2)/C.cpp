

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

struct FenwickTreeOneBasedIndexing {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n) {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

	void add(int idx, int val) {
	    for (++idx; idx < n; idx += idx & -idx)
	        bit[idx] += val;
	}

	void range_add(int l, int r, int val) {
	    add(l, val);
	    add(r + 1, -val);
	}

	int point_query(int idx) {
	    int ret = 0;
	    for (++idx; idx > 0; idx -= idx & -idx)
	        ret += bit[idx];
	    return ret;
	}
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    vector<int> ans(n);
   	vector<int> times(n);

   	vector<int> psum(n + 1, 0);

   	FenwickTreeOneBasedIndexing ft(n);
   	for(int i = 1; i <= n; i++){
   		psum[i] = psum[i - 1] + b[i - 1];
   	}

   	for(int i = n - 1; i >= 0; i--){	

   		int l = i;
   		int u = n - 1;
   		int ind = n;
   		while(l <= u){
   			int mid = (l + u) / 2;
   			int x = psum[mid + 1] - psum[i];
   			if(x > a[i]){
   				ind = mid;
   				u = mid - 1;
   			}
   			else{
   				l = mid + 1;
   			}
   		}

   		if(ind > i){
   			ft.range_add(i, ind - 1, 1);

   		}
   		if(ind != n){
   			int rem = psum[ind] - psum[i];
   			ans[ind] += a[i] - rem;
   		}
   	}


   	for(int i = 0; i < n; i++){
   		cout << b[i] * ft.point_query(i) + ans[i] << " ";
   	}
   	cout << "\n";


}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}