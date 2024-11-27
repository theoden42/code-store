

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
	multiset<int> mins;
	multiset<int> maxs;
	vector<vector<int>> vp(n);
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
		mins.insert(min(x, y));
		maxs.insert(x);
		maxs.insert(y);
	}

	// debug(vp);


	int mx = INF + 5;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < 2; j++){

			int chosenmx = vp[i][j];
			int pair_max = *(--mins.end());
			if(pair_max > chosenmx)
				continue;

			maxs.erase(maxs.find(vp[i][j]));
			maxs.erase(maxs.find(vp[i][(j + 1) % 2]));
			auto it = maxs.upper_bound(vp[i][j]);
			if(it != maxs.begin())
				it--;
			int diff = abs(*it - chosenmx);
			mx = min(mx, diff);
			maxs.insert(vp[i][j]);
			maxs.insert(vp[i][(j + 1) % 2]);
		}
	}

	cout << mx << "\n";

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