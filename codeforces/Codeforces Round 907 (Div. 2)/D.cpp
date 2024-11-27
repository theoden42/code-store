

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

int get(int mx){
	int sum = 0;
	int lst = 3;
	// debug(mx);
	for(int i = 2; i <= 60 && (1ll << i) <= mx; i++){
		int l = (1ll << i);
		int r = min((1ll << (i + 1)) - 1, mx);
		if(l > mx)
			break;
		int lst = l;
		int val = 1;
		for(int j = 1; j <= 60; j++){
			if((r + 1) / (double) val <= i)
				break;
			val *= i;
			int left = max(l, val);
			int right = 0;
			if((r + val) / val <= i){
				right = r;
			} else {
				right = min(r, val * i - 1);
			}

			if(left <= right){
				int len = (right - left + 1) % MOD;
				int val = len * j;
				val %= MOD;
				sum += val;
				sum %= MOD;
			}

		}
	}

	return sum;
}

void solve() {
	int l, r;
	cin >> l >> r;
	int val = get(r) - get(l - 1);
	cout << val << "\n";

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