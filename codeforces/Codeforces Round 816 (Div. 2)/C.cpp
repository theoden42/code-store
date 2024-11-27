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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
	ll sum = 0;
	sum += (n * (n + 1)) / 2;
 
	for(int i = 0; i < n; i++){
		if(i == 0 || a[i - 1] != a[i]){
			sum += i * (n - i);
		}
	}

	for(int j = 0; j < m; j++){
		int x, i;
		cin >> i >> x;
		i--;
		if(a[i] == x){
			cout << sum << "\n";
			continue;
		}

		if(i > 0 && a[i - 1] == a[i]){
			sum += i * (n - i);
		}
		if(i < n - 1 && a[i + 1] == a[i]){
			sum += (i + 1) * (n - i - 1);
		}

		a[i] = x;

		if(i > 0 && a[i - 1] == a[i]){
			sum -= i * (n - i);
		}
		if(i < n - 1 && a[i + 1] == a[i]){
			sum -= (i + 1) * (n - i - 1);
		}


		cout << sum << "\n";
	}

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