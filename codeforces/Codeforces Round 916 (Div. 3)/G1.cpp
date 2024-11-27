

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
const ll MOD = 998244353;
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
	int n;
	cin >> n;
	int csz = n;
	n *= 2;
	vector<int> left(csz + 1, 1e9), right(csz + 1, -1), c(n + 1), grp(n + 1);
	vector<int> left_ind(n + 1, 1e9), right_ind(n + 1, -1);
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	for(int i = 1; i <= n; i++){
		if(left[c[i]] == 1e9){
			left[c[i]] = i;
		}
	}
	for(int i = n; i >= 1; i--){
		if(right[c[i]] == -1){
			right[c[i]] = i;
		}
	}
	vector<pair<int,int>> st;
	for(int i = 1; i <= n / 2; i++){
		st.push_back({left[i], right[i]});
	}
	sort(all(st));
	vector<pair<int,int>> x;
	for(auto [a, b]: st){
		if(x.empty() || x.back().second < a){
			x.push_back({a, b});
		} else {
			x.back().second = max(x.back().second, b);
		}
	}
	// debug(x);
	int sz = x.size();
	vector<int> countgp(sz);
	int count = 0;
	int ind = 0;
	for(auto [a, b]: x){
		while(ind <= b){
			grp[ind] = count;
			ind++;
		}
		count++;
	}

	for(int i = 1; i <= n; i++){
		left_ind[i] = left[c[i]];
		right_ind[i] = right[c[i]];
	}
	// debug(left_ind, right_ind);

	// debug(grp);

	RMQ<int,false> min_q(left_ind);
	RMQ<int,true> max_q(right_ind);

	for(int i = 1; i <= n; i++){
		if(right_ind[i] == i)
			continue;
		int l = i;
		int r = right_ind[i];
		// debug(i);
		while(r - l < n){
			int nl = min_q.query_value(l, r);
			int nr = max_q.query_value(l, r);
			if(nl >= l && nr <= r){
				break;
			} 
			l = nl;
			r = nr;
		}
		if(x[grp[i]].first == l && x[grp[i]].second == r){
			countgp[grp[i]] += 2;
		}
	}

	// debug(countgp);

	int ans = 1;
	for(auto c: countgp){
		ans *= c;
		ans %= MOD;
	}

	cout << x.size() << " " << ans << "\n";
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