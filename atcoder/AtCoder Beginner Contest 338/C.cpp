

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
	vector<int> q(n);
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> q[i];
	}
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		cin >> b[i];
	}

	int ans = 0;
	for(int x = 0; x <= 1e6; x++){
		int count = x;
		int f = 1;
		vector<int> left(n);
		for(int j = 0; j < n; j++){
			if(q[j] < x * a[j]){
				f = 0;break;
			}
			left[j] = q[j] - x * a[j];
		}
		// debug(left, x);
		if(!f){
			break;
		}
		int mxb = 1e9;
		for(int j = 0; j < n; j++){
			if(b[j] != 0){
				int canmake = left[j] / b[j];
				mxb = min(mxb, canmake);
			}
		}
		count += mxb;
		ans = max(ans, count);
	}

	cout << ans << "\n";

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