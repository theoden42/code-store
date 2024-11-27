

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
	vector<vector<int>> v(m, vector<int>(n, 0));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> v[j][i];
		}
	}

	for(int i = 0; i < m; i++){
		sort(all(v[i]));
	}

	ll count = 0;

	for(int i = 0; i < m; i++){

		ll t = 0;
		vector<int> prefix(n, 0);
		prefix[0] = v[i][0];
		for(int j = 1; j < n; j++){
			t +=  j * v[i][j] - prefix[j - 1];
			prefix[j] = v[i][j] + prefix[j - 1];
		}

		count += t;
	}
	cout << count << "\n";
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