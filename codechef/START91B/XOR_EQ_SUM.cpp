

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


int get(int ind, int tight, int bound, vector<vector<int>>& dp){
	int temp = (bound >> ind);

	debug(temp);

	if(temp == 0)return 1;

	if(dp[ind][tight] != -1)return dp[ind][tight];

	int ans = 0;
	int bit = (bound & (1 << ind));

	if(bit && tight){
		ans += get(ind + 1, tight, bound, dp);
		ans += get(ind + 1, 0, bound, dp);
	}
	if(bit && !tight){
		ans += 2 * get(ind + 1, 0, bound, dp);
	}
	if(!bit && tight){
		ans += get(ind + 1, tight, bound, dp);
	}
	if(!bit && !tight){
		ans += 2 * get(ind + 1, 0, bound, dp);
	}

	return dp[ind][tight] = ans;

}


void solve() {
	int l, r;
	cin >> l >> r;


	int x = 0;
	while(r != 0){
		x++;
		r /= 2;
	}	

	if(l == 0){
		cout << (1ll << x) << "\n";
		return;
	}

	int val = (1ll << (x - 1));
	int sum = 0;

	debug(val);

	while(val > l){
		sum += (val - l);
		val >>= 1;
	}

	cout << sum << "\n";

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