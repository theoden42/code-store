

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

int cleanupDataset(string dataset, int x, int y){
	unordered_map<char,int> mp;
	int n = dataset.size();
	for(int i = 0; i < n; i++){
		mp[dataset[i]] += 1;
	}
	if(x < y){
		int ans = 0;
		int count = 0;
		for(auto [a, b]: mp){
			if(b & 1){
				ans += x * (b / 2);
				count += 1;
			} else {
				ans += x * (b / 2);
			}
		}
		ans += y * (count / 2);
		return ans;
	} else {
		int mx = 0;
		for(auto [a, b]: mp){
			mx = max(mx, b);
		}
		int ans = 0;
		if(2 * mx <= n){
			ans += y * (n / 2);
		} else {
			int left = 2 * mx - n;
			ans += y * (n - left) / 2;
			ans += x * (left / 2);
		}
		return ans;
	}
}

void solve() {
    cout << cleanupDataset("ouio", 4, 2) << endl;
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