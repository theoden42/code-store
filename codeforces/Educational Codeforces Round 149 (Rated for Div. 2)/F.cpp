

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
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	multiset<pair<int,int>> mst;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		mst.insert({a[i], i});
	}
	vector<int> temp;
	map<int,int> mp;
	for(int i = 1; i <= k; i++){
		auto it = mst.begin();
		mp[it->second] = 1;
		mst.erase(it);
	}

	for(int i = 0; i < n; i++){
		if(mp[i] == 1){
			temp.push_back(a[i]);
		}
	}

	int sum = 0;
	sum = accumulate(all(temp), 0ll);
	int mx = sum;
	int count = 0;
	for(int i = 0; i < temp.size(); i++){
		count += temp[i];
		int t = max(count, sum - count);
		mx = min(mx, t);
	}

	cout << mx << "\n";

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