

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
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i)
		cin >> v[i];

	vector<int> p(n);
	for(int i = 0; i < n; i++)
		cin >> p[i];

	vector<int> temp(n);

	for(int i = 0; i < n; i++){
		temp[i] = v[p[i] - 1];
	}
	v.assign(all(temp));

	ordset<pair<int,int>> mst;
	for(int i = 0; i < n; i++){
		mst.insert({v[i], i});
	}

	int mx = 0;
	int num = 0;

	for(int k = 1; k <= n; k++){

		int sz = mst.size();
		auto [nmx, _] = (sz - k >= 0 ? *mst.find_by_order(sz - k) : *mst.find_by_order(0));
		int tot = min(n - k + 1, k);
		int val =  nmx * tot;

		if(val > mx){
			mx = val;
			num = k;
		}

		mst.erase(mst.find({v[k - 1], k - 1}));
	}

	cout << mx << " " << num << "\n";
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