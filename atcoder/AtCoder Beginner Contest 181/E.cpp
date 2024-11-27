

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
	int n, m;
	cin >> n >> m;
	vector<int> h(n);
	vector<int> w(m);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < m; i++){
		cin >> w[i];
	}

	sort(all(h));
	sort(all(w));
	vector<int> prefix(n), suffix(n);

	for(int i = 1; i < n; i++){
		prefix[i] = (i - 2 >= 0 ? prefix[i - 2] : 0);
		prefix[i] += (h[i] - h[i - 1]);
	}

	for(int i = n - 2; i >= 0; i--){
		suffix[i] = (i + 2 < n ? suffix[i + 2] : 0);
		suffix[i] += (h[i + 1] - h[i]); 
	}

	int mnans = 1e18;

	for(int i = 0; i < m; i++){
		auto it = upper_bound(all(h), w[i]);
		int ind = it - h.begin();

		if(ind & 1){
			int ans = (ind - 2 >= 0 ? prefix[ind - 2] : 0);
			ans += (w[i] - h[ind - 1]);
			ans += (ind < n ? suffix[ind] : 0);
			mnans = min(mnans, ans);
		} else {
			int ans = (ind - 1 >= 0 ? prefix[ind - 1] : 0);
			ans += (h[ind] - w[i]);
			ans += (ind + 1 < n ? suffix[ind + 1] : 0);
			mnans = min(mnans, ans);
		}
	}


	cout << mnans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}