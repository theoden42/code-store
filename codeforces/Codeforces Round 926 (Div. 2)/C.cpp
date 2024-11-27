

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
	int k, x, a;
	cin >> k >> x >> a;
	if(x >= a){
		cout << "NO\n";
		return;
	} 
	if(k > x + 1){
		cout << "YES\n";
	} else {
		int current = a - 1;
		int sum = 1;
		for(int i = 2; i <= x + 1; i++){
			int nxt = (sum) / (k - 1) + 1;
			if(current < nxt){
				cout << "NO\n";
				return;
			} 
			current -= nxt;
			sum += nxt;
		}

		cout << "YES\n";
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