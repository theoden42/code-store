

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

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), v(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		v[i] = a[i] + 1 + i;
	}
	map<int,int> mp;
	for(int i = 0; i < n; i++){
		mp[v[i]] += 1;
	}
	multiset<pair<int,int>> mst;
	for(auto it: mp){
		mst.insert(it);
	}

	vector<int> ans;

	while(!mst.empty()){
		auto [val, v] = *(--mst.end());
		mst.erase(--mst.end());
		ans.push_back(val);
		if(mp[val - 1] != 0){
			mst.erase(mst.find({val - 1, mp[val - 1]}));
		}
		mp[val - 1] += v - 1;
		if(mp[val - 1] != 0){
			mst.insert({val - 1, mp[val - 1]});
		}
	}

	for(auto x: ans){
		cout << x << " ";
	}
	cout << "\n";

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