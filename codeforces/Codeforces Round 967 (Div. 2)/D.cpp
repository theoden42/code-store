

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
	vector<int> a(n);
	vector<vector<int>> pos(n + 1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		pos[a[i]].push_back(i);
	}
	vector<int> ans;
	vector<pair<int,int>> elg;
	multiset<int> elems;
	multiset<pair<int,int>> mst;
	vector<int> vis(n + 1);
	for(int i = 1; i <= n; i++){
		if(pos[i].empty())
			continue;
		mst.insert({pos[i].back(), i});
		elg.push_back({pos[i][0], i});
	}
	sort(all(elg));
	int ind = 0;
	int count = 0;
	int currind = 0;
	while(!mst.empty()){
		auto lstind = mst.begin()->first;
		int prvind = currind;
		while(ind <= lstind){
			if(!vis[a[ind]]){
				elems.insert(a[ind]);
			}
			ind += 1;
		}
		// debug(elems, mst);
		if(count & 1){
			auto v = *elems.begin();
			// debug(v, pos[v]);
			mst.erase(mst.find({pos[v].back(), v}));
			int nind = *lower_bound(all(pos[v]), prvind);
			vis[v] = 1;
			elems.erase(v);
			while(currind <= nind){
				if(elems.find(a[currind]) != elems.end()){
					elems.erase(elems.find(a[currind]));
				}
				currind += 1;
			}
			ans.push_back(v);
		} else {
			auto v = *prev(elems.end(), 1);
			// debug(v, pos[v]);
			mst.erase(mst.find({pos[v].back(), v}));
			int nind = *lower_bound(all(pos[v]), prvind);
			vis[v] = 1;
			elems.erase(v);
			while(currind <= nind){
				if(elems.find(a[currind]) != elems.end()){
					elems.erase(elems.find(a[currind]));
				}
				currind += 1;
			}
			ans.push_back(v);
		}
		count += 1;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " \n"[i == ans.size() - 1];
	}
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