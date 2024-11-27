

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
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<pair<int,int>> ans;
	int xind = min_element(all(a)) - a.begin();
	int yind = max_element(all(a)) - a.begin();

	if(a[xind] + a[yind] >= 0){
		// for(int i = 0; i < n; i++){
		// 	if(i == yind || a[i] >= 0)
		// 		continue;
		// 	ans.push_back({i, yind});
		// 	a[i] += a[yind];
		// }
		ans.push_back({0, yind});
		ans.push_back({0, yind});
		a[0] += 2 * a[yind];
		for(int i = 1; i < n; i++){
			ans.push_back({i, i - 1});
			a[i] += a[i - 1];
		}

	} else {
		// for(int i = 0; i < n; i++){
		// 	if(i == xind || a[i] < 0)
		// 		continue;
		// 	ans.push_back({i, xind});
		// 	a[i] += a[xind];
		// }
		ans.push_back({n - 1, xind});
		ans.push_back({n - 1, xind});
		a[n - 1] += 2 * a[xind];
		for(int i = n - 2; i >= 0; i--){
			ans.push_back({i, i + 1});
			a[i] += a[i + 1];
		}
	}

	debug(a);

	cout << ans.size() << "\n";
	for(auto it: ans){
		cout << it.first + 1 << " " << it.second + 1 << "\n";
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