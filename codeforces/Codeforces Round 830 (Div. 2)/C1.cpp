

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	int L, R;
	cin >> L >> R;

	int l = 0;
	int r = n - 1;
	int mn = n;


	int sum = 0;
	int xr = 0;
	for(int i = 0; i < n; i++){
		sum += a[i];
		xr ^= a[i];
	}

	if(sum == xr){
		cout << 1 << " " << 1 << "\n";
		return;
	}

	int tempsum = 0;
	int tempxr = 0;
	int j = 0;
	for(int i = 0; i < n; i++){
		j = max(j, i);
		while(j < n && tempsum - tempxr != sum - xr){
			tempsum += a[j];
			tempxr ^= a[j];
			j++;
		}

		if(tempsum - tempxr != sum - xr)continue;

		int len = j - i;
		if(len < mn){
			mn = len;
			l = i;
			r = j - 1;
		}
		tempsum -= a[i];
		tempxr ^= a[i];

	}

	cout << l + 1 << " " << r + 1  << "\n";

	int checksum = 0;
	int checkxor = 0;
	for(int i = l; i <= r; i++){
		checksum += a[i];
		checkxor ^= a[i];
	}

	assert(checksum - checkxor == sum - xr);

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