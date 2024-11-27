

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
	vector<vector<int>> a(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i].push_back(x);
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[i].push_back(x);
		a[i].push_back(i);
	}
	sort(all(a));

	vector<int> ans(n, 0);
	ans[n - 1] = 1;

	vector<int> pmx(n);
	pmx[0] = a[0][1];
	for(int i = 1; i < n; i++){
		pmx[i] = max(a[i][1], pmx[i - 1]);
	}

	map<int,int> ind;
	vector<pair<int,int>> sortb(n);
	for(int i = 0; i < n; i++){
		sortb[i] = {a[i][1], i};
	}

	sort(all(sortb));
	int mx = 0;
	for(int i = 0; i < n; i++){
		mx = max(mx, sortb[i].second);
		ind[sortb[i].first] = mx;
	}

	mx = 0;
	for(int i = n - 2; i >= 0; i--){
		int mx = pmx[i];
		int curr_ind = ind[mx];
		if(curr_ind <= i){
			ans[i] = 0;
		} else {
			ans[i] = ans[curr_ind];
		}
	}
	vector<int> finans(n);
	for(int i = 0; i < n; i++){
		finans[a[i][2]] = ans[i];
	}
	ans = finans;

	string fin = "";
	for(int i = 0; i < n; i++){
		fin += (char)('0' + ans[i]);
	}

	cout << fin << "\n";

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