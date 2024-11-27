

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

void solve() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<int> a(n), b(m);
	multiset<int> mst;
	vector<vector<int>> cannot(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
		mst.insert(b[i]);
	}
	for(int j = 0; j < l; j++){
		int c, d;
		cin >> c >> d;
		c--;
		d--;
		cannot[c].push_back(d);
	}

	int mx = 0;
	for(int i = 0; i < n; i++){
		for(auto ind: cannot[i]){
			mst.erase(mst.find(b[ind]));
		}
		if(!mst.empty()){
			int p = a[i] + *mst.rbegin();
			mx = max(mx, p);
		}
		for(auto ind: cannot[i]){
			mst.insert(b[ind]);
		}
	}

	cout << mx << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}