

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
    int n, m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++){
    	cin >> x[i];
    }
    int cl = 0;
    int cr = 0;
    set<int> mst;
	for(int i = 0; i < n; i++){
		if(x[i] == -1)cl++;
		else if(x[i] == -2)cr++;
		else mst.insert(x[i]);
	}
	if(mst.empty()){
		int ans = min(m, max(cl, cr));
		cout << ans << "\n";
		return;
	}

	int sz = mst.size();
	vector<int> xn;
	while(!mst.empty()){
		auto it = mst.begin();
		xn.push_back(*it);
		mst.erase(it);
	}

	int cn1 = min(sz + cr, m);
	int cn2 = min(sz + cl, m);

	int ans = max(cn1, cn2);
	sort(all(xn));


	for(int i = 0; i < sz; i++){

		int temp = 1;
		int left = xn[i] - 1;
		int right = m  - xn[i];
		temp += min(left, i + cl);
		temp += min(right, sz - i - 1 + cr);
		ans = max(ans, temp);
	}
	cout << ans << "\n";


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