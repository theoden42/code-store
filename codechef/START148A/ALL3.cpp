

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
	vector<vector<int>> pos(4);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		pos[x].push_back(i);
	}

	int ans = 0;

	for(int i = 1; i <= 3; i++){
		int left = pos[i][0];
		int right = pos[i].back();
		int v;
		if(i == 1)
			 v = 3;
		else if(i == 2)
			v = 1;
		else 
			v = 2;

		auto left_it = lower_bound(all(pos[v]), right);
		auto right_it = upper_bound(all(pos[v]), left);
		int left_ind, right_ind;

		if(left_it == pos[v].begin()){
			left_ind = -1;
		} else {
			left_ind = *std::prev(left_it, 1);
		}

		if(right_it == pos[v].end()){
			right_ind = n;
		} else {
			right_ind = *right_it;
		}

		if(left_ind >= left || right_ind <= right)
			continue;

		int temp = (left - left_ind) * (right_ind - right);
		ans += temp;
	}

	ans = (n * (n + 1)) / 2 - ans;

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