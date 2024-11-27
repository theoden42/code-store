

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
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	for(int i = 0; i < n; i++)
		cin >> b[i];

	vector<pair<int,int>> vp(n);
	for(int i = 0; i < n; i++){
		vp[i] = {a[i], b[i]};
	}
	sort(all(vp));
	int mx = vp.back().first;
	ordset<pair<int,int>> mst;
	for(int i = 0; i < n; i++){
		mst.insert({vp[i].first, i});
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		if(vp[i].second == 1){
			int val = vp[i].first + k;
			mst.erase(mst.find({vp[i].first, i}));
			auto it = mst.find_by_order(n / 2 - 1);
			val += it->first;
			mst.insert({vp[i].first, i});
			ans = max(ans, val);
		}
	}

	auto check = [&](int mid){
		vector<pair<int,int>> temp;
		for(int i = 0; i < n - 1; i++){
			if(vp[i].first < mid){
				temp.push_back(vp[i]);
			}
		}
		int rem = k;
		int count = 0;
		for(int i = (int)temp.size() - 1; i >= 0; i--){
			int x = mid - temp[i].first;
			if(temp[i].second && rem >= x){
				rem -= x;
				count += 1;
			}
		}
		if((int)temp.size() - count <= n / 2 - 1){
			return true;
		} else {
			return false;
		}
	};

	int lb = mx;
	int ub = 1e18;
	while(lb <= ub){
		int mid = lb + (ub - lb)/ 2;
		int md = mid - mx;
		if(check(md)){
			ans = max(ans, mid);
			lb = mid + 1;
		} else {
			ub = mid - 1;
		}
	}

	cout << ans << "\n";

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