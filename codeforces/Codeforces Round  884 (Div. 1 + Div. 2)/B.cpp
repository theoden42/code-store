

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
	int n;
	cin >> n;
	if(n == 1)
		cout << 1 << "\n";
	else if(n == 2)
		cout << "1 2" << "\n";
	else{
		vector<int> ans(n);
		ans[0] = 2;
		ans[n / 2] = 1;
		ans[n - 1] = 3;
		// debug(ans);
		int ind = 1;
		for(int i = 4; i <= n; i++){
			if(ind == n / 2){
				ind++;
			}
			ans[ind] = i;
			ind++;
		}
		for(auto x: ans){
			cout << x << " ";
		}
		cout << "\n";
	}
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