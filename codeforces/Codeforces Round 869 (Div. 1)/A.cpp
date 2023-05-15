

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
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<int> prefix(n + 1);
	map<int,int> mp;
	prefix[0] = 0;
	prefix[1] = 1;

	for(int i = 1; i < n - 1; i++){
		if(a[i] <= a[i - 1] && a[i] >= a[i + 1]){
			prefix[i + 1] = prefix[i] + 1;
		}
		else{
			prefix[i + 1] = prefix[i];
		}
	}	

	for(int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		if(r - l + 1 > 2){
			int ans = r - l + 1 - (prefix[r - 1] - prefix[l]);
			cout << ans << "\n";
		}
		else{
			cout << r - l + 1 << "\n";
		}
	}
};




int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}