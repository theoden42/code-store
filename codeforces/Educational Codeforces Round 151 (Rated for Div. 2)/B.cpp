

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
	int xa, ya;
	cin >> xa >> ya;
	int xb, yb;
	cin >> xb >> yb;
	int xc, yc;
	cin >> xc >> yc;

	int mncol = 0;
	int mnrow = 0;

	if((xb >= xa && xc >= xa) || (xb <= xa && xc <= xa)){
		mnrow = min(abs(xa - xb), abs(xa - xc));;
	}

	if((yb >= ya && yc >= ya) || (yb <= ya && yc <= ya)){
		mncol = min(abs(ya - yb), abs(ya - yc));;
	}

	if(xb == xc){
		int ans = abs(xb - xa) + mncol + 1;
		cout << ans << "\n";
	}
	else if(yb == yc){
		int ans = abs(yb - ya) + mnrow + 1;
		cout << ans << "\n";
	}
	else{
		cout << mnrow + mncol + 1 << "\n";
	}

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