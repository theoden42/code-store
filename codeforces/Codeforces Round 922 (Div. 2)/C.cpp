

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
	int a, b, r;
	cin >> a >> b >> r;

	int ind = 0;
	int f = 0;
	for(int i = 60; i >= 0; i--){
		int b1 = ((a >> i) & 1ll);
		int b2 = ((b >> i) & 1ll);
		if(b1 == b2){
			continue;
		} else{
			if(b1 < b2){
				f = -1;
				ind = i;
			} else {
				f = 1;
				ind = i;
			}
			break;
		}
	}

	int tr = 0;	
	for(int i = ind - 1; i >= 0; i--){
		int b1 = ((a >> i) & 1ll);
		int b2 = ((b >> i) & 1ll);
		if(b1 == b2)
			continue;
		if(f == 1){
			if(b2 > b1)
				continue;
			else{
				int ntr = (tr | (1ll << i));
				if(ntr <= r){
					tr = ntr;
				}
			}
		} else {
			if(b1 > b2)
				continue;
			else{
				int ntr = (tr | (1ll << i));
				if(ntr <= r){
					tr = ntr;
				}
			}
		}
	}

	int val = abs((a ^ tr) - (b ^ tr));
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