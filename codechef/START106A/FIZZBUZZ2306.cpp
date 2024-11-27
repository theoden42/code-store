

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

vector<pair<int,int>> dis = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int find(int n, int m, int x, int y, int a, int b){
	if(a <= 0 || a > n)
		return 0;
	if(b <= 0 || b > m)
		return 0;

	if(a == x - 1){
		int ans = m * (x - 1);
		return ans;
	} else if( a == x + 1){
		int ans = m * (n - x);
		return ans;
	} else if(b == y - 1){
		int ans = n * (y - 1);
		return ans;
	} else {
		int ans = n * (m - y);
		return ans;
	}
}


void solve() {
    int n, m;
    cin >> n >> m;
    int x, y;
    cin >> x >> y;

    int v1 = find(n, m, x, y, x - 1, y);
    int v2 = find(n, m, x, y, x + 1, y);
    int v3 = find(n, m, x, y, x, y - 1);
    int v4 = find(n, m, x, y, x, y + 1);

    cout << max({v1, v2, v3, v4}) << "\n";
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