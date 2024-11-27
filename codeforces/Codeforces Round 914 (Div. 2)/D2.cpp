

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
		// debug(n - 1, from, to);;
		assert(0 <= from && from <= to && to <= n - 1);
		int lg = highest_bit(to - from + 1);
		return better(range_min[lg][from], range_min[lg][to - (1 << lg) + 1]);
	}
};


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    map<int,vector<int>> mpa, mpb;
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    	mpa[a[i]].push_back(i);
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    	mpb[b[i]].push_back(i);
    }

    RMQ<int,false> rb(b);
    RMQ<int,true> ra(a);

    for(int i = 0; i < n; i++){
        if(a[i] == b[i])
            continue;

        int f1 = 0;
        int f2 = 0;
        auto it1 = lower_bound(all(mpa[b[i]]), i);
        auto it2 = lower_bound(all(mpa[b[i]]), i);
        // debug(mpa[b[i]], i);

        if(it1 != mpa[b[i]].begin()){
        	f1 = 1;
        	it1--;;
        	// debug(*it1);
        	int vb = rb.query_value(*it1, i);
        	int va = ra.query_value(*it1, i);
        	if(vb < b[i] || va > b[i])
        		f1 = 0;
        }
        if(it2 != mpa[b[i]].end()){
        	f2 = 1;
        	// debug(*it2, i);
        	int vb = rb.query_value(i, *it2);
        	int va = ra.query_value(i, *it2);
        	if(vb < b[i] || va > b[i])
        		f2 = 0;
        }

        if(!f1 && !f2){
            // debug(i);
            cout << "NO\n";
            return;
        }

    }
    cout << "YES\n";
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