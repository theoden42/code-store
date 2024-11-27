

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

template<typename T, bool maximum_mode = false>
struct RMQ {
	int n = 0;
	vector<vector<T>> range_min;
	RMQ(const vector<T> &values = {}) {
		if (!values.empty())
			build(values);
	}
	static int highest_bit(int x) {
		return x == 0 ? -1 : 31 - __builtin_clz(x);
	}
	static T better(T a, T b) {
		return maximum_mode ? max(a, b) : min(a, b);
	}
	void build(const vector<T> &values) {
		n = int(values.size());
		int levels = highest_bit(n) + 1;
		range_min.resize(levels);
		for (int k = 0; k < levels; k++)
			range_min[k].resize(n - (1 << k) + 1);
		if (n > 0)
			range_min[0] = values;

		for (int k = 1; k < levels; k++)
			for (int i = 0; i <= n - (1 << k); i++)
				range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
	}
	void show() const {
		for (int i = 0; i < int(range_min.size()); i++) {
			for (int j = 0; j < int(range_min[0].size()); j++) {
				cout << range_min[i][j] << " \n"[j + 1 == range_min[0].size()];
			}
		}
	}
	T query_value(int from, int to) const {
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = highest_bit(to - from + 1);
		return better(range_min[lg][from], range_min[lg][to - (1 << lg) + 1]);
	}
};

#define int long long 

void solve() {
   int n, q;
   cin >> n >> q;
   vector<int> h(n);
   for(int i = 0; i < n; i++){
   		cin >> h[i];
   }

   RMQ<int,true> rmq(h);
   vector<vector<int>> qry(q);
   for(int i = 0; i < q; i++){
   		int l, r;
   		cin >> l >> r;
   		l--;r--;
   		qry[i] = {r, l, i};
   }
   sort(all(qry));	
   reverse(all(qry));
   vector<int> ans(q);
   vector<int> st;
   int nr = n - 1;
   auto fix = [&](int r){
   	while(nr > r){
   		while(!st.empty() && st.back() < h[nr]){
   			st.pop_back();
   		}
   		st.push_back(h[nr]);
   		nr -= 1;
   	}
   };
	auto calc = [&](int mx){
		int lb = 0;
		int ub = st.size() - 1;
		int ans = 0;
		while(lb <= ub){
			int mid = lb + (ub - lb) / 2;
			if(st[mid] > mx){
				ans = mid + 1;
				lb = mid + 1;
			} else {
				ub = mid - 1;
			}
		}
		return ans;
	};

   for(int i = 0; i < q; i++){
   		int curr_r = qry[i][0];
   		int curr_l = qry[i][1];
   		int curr_ind = qry[i][2];
   		// debug(curr_l, curr_r, curr_ind);
   		fix(curr_r);
   		// debug(st);
   		int mx = rmq.query_value(curr_l + 1, curr_r);
   		ans[curr_ind] = calc(mx);
   }

   for(int i = 0; i < q; i++){
   		cout << ans[i] << "\n";
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