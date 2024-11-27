

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
// #define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int mx = *max_element(all(a));
	vector<int> f(mx + 5);
	for(int i = 0; i < n; i++){
		for(int j = 1; j * j <= a[i]; j++){
			if(a[i] % j != 0)
				continue;

			int f1 = j;
			int f2 = a[i] / j;
			f[f1] += 1;
			if(f1 != f2)
				f[f2] += 1;
		}
	}

	vector<ll> count(mx + 1);
	for(int i = mx; i >= 1; i--){
		count[i] = (1ll * f[i] * (f[i] - 1)) / 2;
		for(int j = 2; j * i <= mx; j++){
			count[i] -= count[j * i];
		}
	}

	// debug(count);

	cout << count[1] << "\n";

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