

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
	int l, r;
	cin >> l >> r;
	vector<pair<int,int>> val;

	int st = l;
	while(st != r){
		int x = 1;
		while(x < (1ll << 61) && st % x == 0){
			x *= 2;
		}
		x /= 2;
		int end = st + x;
		if(end <= r){
			val.push_back({st, end});
			st = end;
		} else { 
			int df = r - st;
			while(x > df){
				x /= 2;
			}
			end = st + x;
			val.push_back({st, end});
			st = end;
		}
	}

	cout << val.size() << "\n";
	for(auto [a, b]: val){
		cout << a << " " << b << "\n";
	}
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