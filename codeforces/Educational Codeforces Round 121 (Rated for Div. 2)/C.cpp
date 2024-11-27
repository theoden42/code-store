

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
	vector<int> k(n), h(n);
	for(int i = 0; i < n; i++){
		cin >> k[i];
	}
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	vector<pair<int,int>> vals(n);
	for(int i = 0; i < n; i++){
		vals[i] = {k[i] - h[i] + 1, k[i]};
	}
	multiset<pair<int,int>> mst;
	for(int i = 0; i < n; ++i){
		mst.insert(vals[i]);
	}

	long long sum = 0;
	int start = -1;
	while(!mst.empty()){
		auto it = mst.begin();
		int start = it->first;
		int end = start;
		while(!mst.empty() && mst.begin()->first <= end){
			end = max(end, mst.begin()->second);
			mst.erase(mst.begin());
		}
		int v = end - start + 1;
		sum += (v * (v + 1)) / 2;
	}

	cout << sum << "\n";
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