
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

	vector<vector<int>> a(n, vector<int>(m));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}

	vector<RMQ<int,false>> min_seg(n);
	for(int i = 0; i < n; i++){
		min_seg[i].build(a[i]);
	}


	int l = 1;
	int u = n;
	int mx = 0;

	auto check = [&](int l){
		for(int i = 0; i <= m - l; i++){
			vector<int> ch(n, 0);
			int low = i;
			int high = i + l - 1;


			for(int j = 0; j < n; ++j){
				int mn = min_seg[j].query_value(low, high);
				if(mn >= l){
					ch[j] = 1;
				}
			}
			int count = 0;
			for(int i = 0; i < n; i++){
				if(ch[i])count++;
				else{
					count = 0;
				}

				if(count >= l)return true;
			}
		}
		return false;
	};


	while(l <= u){
		int mid = (l + u) / 2;

		if(check(mid)){
			mx = max(mx, mid);
			l = mid + 1;
		}
		else{
			u = mid - 1;
		}
	}

	cout << mx << "\n";

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