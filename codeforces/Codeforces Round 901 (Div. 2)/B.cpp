

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
	int n, m, k;
	cin >> n >> m >> k;
	multiset<int> a, b;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a.insert(x);
	}
	for(int i = 0; i < m; i++){
		int x;
		cin >> x;
		b.insert(x);
	}

	int sm = *a.begin();
	int lg = *(--b.end());
	if(sm < lg){
		a.erase(a.begin());
		b.erase(--b.end());
		a.insert(lg);
		b.insert(sm);
	}

	if(k & 1){
		int sum = 0;
		for(auto it: a){
			sum += it;
		}
		cout << sum << "\n";
	} else {
		int sm = *b.begin();
		int lg = *(--a.end());
		if(sm < lg){
			a.erase(--a.end());
			b.erase(b.begin());

			a.insert(sm);
			b.insert(lg);
		}
		int sum = 0;
		for(auto it: a){
			sum += it;
		}
		cout << sum << "\n";
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