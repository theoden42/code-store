

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
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int,int>> vp(k);
	for(int i = 0; i < k; i++){
		cin >> vp[i].first >> vp[i].second;
	}	
	map<int,int> mp;
	mp[n] = m + 1;
	for(auto [r, c]: vp){
		if(mp.find(r) == mp.end()){
			mp[r] = c;
		} else {
			mp[r] = min(mp[r], c);
		}
	}
	vector<pair<int,int>> f;
	for(auto [r, c]: mp){
		f.push_back({r, c});
	}
	multiset<pair<int,int>> mst;
	int lst = m + 1;
	while(!f.empty()){
		auto [r, c] = f.back();
		f.pop_back();
		if(c > lst)
			continue;
		mst.insert({r, c});
		lst = c;
	}
	int ans = 0;
	int lrow = 0;
	for(auto [r, c]: mst){
		int numr = (r - lrow) * (c - 1);
		ans += numr;
		lrow = r;
	}
	cout << ans << "\n";
	// debug(mst);

	for(int i = 0; i < k; i++){
		if(mst.find(vp[i]) == mst.end()){
			cout << "0 ";
			continue;
		}
		auto it = mst.find(vp[i]);
		int extra = 0;
		if(it == --mst.end()){
			extra = m + 1 - vp[i].second;
		} else {
			int r0 = 0;
			if(it != mst.begin()){
				r0 = (--it)->first;
				++it;
			}
			int r1 = it->first;
			int c1 = it->second;
			// debug(*it);
			int r2 = (++it)->first;
			// debug(mst);
			// debug(*it);
			int c2 = (it)->second;
			// debug(r0, r2, c2);
			extra = (r1 - r0) * (c2 - c1);
		}
		cout << extra << " ";
	}
	cout << "\n";
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