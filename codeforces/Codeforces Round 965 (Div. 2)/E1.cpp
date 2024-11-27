

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

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<ll> p(n + 1);
    for(int i = 0; i < n; i++)
    	cin >> a[i];
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	vp[i] = {a[i], i};
    	p[i + 1] += p[i];
    	p[i + 1] += a[i];
    }

    RMQ<pair<int,int>, true> rmq(vp);
    function<int(int,int)> recur = [&](int l, int r){
    	if(r < l)
    		return 0;
    	if(r == l)
    		return 1;
    	auto [val, ind] = rmq.query_value(l, r);
    	int leftans = recur(l, ind - 1);
    	int rightans = recur(ind + 1, r);
    	int ans = 0;
    	if(p[ind] - p[l] >= val)
    		ans += leftans;
    	if(p[r + 1] - p[ind + 1] >= val)
    		ans += rightans;
    	ans += 1;
    	return ans;
    }; 
    int fin = recur(0, n - 1);
    cout << fin << "\n";
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