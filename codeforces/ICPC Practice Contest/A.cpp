

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
	int n, m, p;
	cin >> n >> m >> p;
	vector<pair<int,int>> judge(n), tar(m), feat(p);
	for(int i = 0; i < n; i++){
		cin >> judge[i].first >> judge[i].second;
	}
	for(int i = 0; i < m; i++){
		cin >> tar[i].first >> tar[i].second;
	}
	for(int i = 0; i < p; i++){
		cin >> feat[i].first >> feat[i].second;
	}

	vector<int> vis_j(n);
	vector<int> vis_t(m);
	vector<int> vis_f(p);

	multiset<vector<int>> mst;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int xd = (judge[i].first - tar[j].first);
			int yd = (judge[i].second - tar[j].second);
			int dst = xd * xd + yd * yd;
			mst.insert({dst, i, j});
		}
	}

	double ans = 0;
	while(!mst.empty()){
		auto v = *mst.begin();
		mst.erase(mst.begin());
		if(vis_j[v[1]] || vis_t[v[2]])
			continue; 
		ans += sqrtl(v[0]);
		vis_j[v[1]] = 1;
		vis_t[v[2]] = 1;
	}

	vis_j.assign(n, 0);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p; j++){
			int xd = (judge[i].first - feat[j].first);
			int yd = (judge[i].second - feat[j].second);
			int dst = xd * xd + yd * yd;
			mst.insert({dst, i, j});
		}
	}

	while(!mst.empty()){
		auto v = *mst.begin();
		mst.erase(mst.begin());
		if(vis_j[v[1]] || vis_f[v[2]])
			continue;
		ans += sqrtl(v[0]);
		vis_j[v[1]] = 1;
		vis_f[v[2]] = 1;
	}

	cout << fixed << setprecision(15) << ans << "\n";
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