

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
	int n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		grid[i] = s;
	}

	vector<vector<int>> leftmost(n, vector<int>(m));
	vector<vector<int>> topmost(n, vector<int>(m));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			leftmost[i][j] = j;
			topmost[i][j] = i;
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(i > 0 && grid[i - 1][j] != 'X'){ 
				leftmost[i][j] = min(leftmost[i][j], leftmost[i - 1][j]);
				topmost[i][j] = min(topmost[i][j], topmost[i - 1][j]);
			}
			if(j > 0 && grid[i][j - 1] != 'X'){
				leftmost[i][j] = min(leftmost[i][j], leftmost[i][j - 1]);
				topmost[i][j] = min(topmost[i][j], topmost[i][j - 1]);
			}
		}	
	}

	vector<int> mincols(m, -1);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(topmost[i][j] == 0){
				leftmost[i][j] = -1;
			}
			mincols[j] = max(mincols[j], leftmost[i][j]);
		}
	}

	RMQ<int, true> rq(mincols);
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int x1, x2;
		cin >> x1 >> x2;
		int mn = rq.query_value(x1 - 1, x2 - 1);
		if(mn > x1 - 1){
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}