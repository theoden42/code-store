

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
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    int mx = a[0];
    int ind = 0;
    for(int i = 0; i < n; i++){
    	if(a[i] > mx){
    		mx = a[i];
    		ind = i;
    	}
    }
    RMQ<int, true> rmq(a);
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++){
    	p[i] = p[i - 1] + a[i - 1];
    }
    vector<pair<int,int>> vp;
    multiset<int> mst;
    for(int i = 0; i < n; i++){
    	mst.insert(a[i]);
    }
    for(int i = 0; i < n; i++){
    	mst.erase(mst.find(a[i]));
    	if(i == 0){
    		if(a[0] + c >= mx){
    			cout << "0" << " \n"[i == n - 1];
    		} else{
    			cout << "1" << " \n"[i == n - 1];
    		}
    	} else if(mst.empty() || *prev(mst.end()) <= a[i]){
    		int lb = 0;
    		int ub = vp.size() - 1;
    		int ans = i;
    		while(lb <= ub){
    			int mid = (lb + ub) / 2;
    			if(vp[mid].first + c < a[i] && rmq.query_value(vp[mid].second, i - 1) < a[i]){
    				ans = vp[mid].second;
    				ub = mid - 1;
    			} else {
    				lb = mid + 1;
    			}
    		}
    		cout << ans << " \n"[i == n - 1];
    	} else {
    		// delete all prev
    		int ans = i;
    		if(a[i] + c + p[i] < *prev(mst.end()))
    			ans += 1;
    		cout << ans << " \n"[i == n - 1];
    	}
    	if(vp.empty() || vp.back().first > a[i] + p[i]){
    		vp.push_back({a[i] + p[i], i});
    	}
    }
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