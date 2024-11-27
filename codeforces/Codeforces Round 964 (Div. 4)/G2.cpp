

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
	int l = 1;
	int r = 1000;
	while(l < r){
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;
		cout << "? " << mid1 << " " << mid2 << endl;
		int x;
		cin >> x;
		int a1 = mid1 * mid2;
		int a2 = (mid1) * (mid2 + 1);
		int a3 = (mid1 + 1) * (mid2 + 1);
		if(x == a3){
			r = mid1;
		} else if(x == a2){
			l = mid1 + 1;
			r = mid2;
		} else if(x == a1) {
			l = mid2 + 1;
		} else {
			assert(false);
		}
	}
	cout << "! " << l << endl;
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