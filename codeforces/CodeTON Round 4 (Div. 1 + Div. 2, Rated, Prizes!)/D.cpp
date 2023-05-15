

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

#define int long long 

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
	int q;
	cin >> q;
	int l = 0;
	int u = 5e18 + 5;


	for(int i = 1; i <= q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int n, a, b;
			cin >> a >> b >> n;

			int lb = 0, ub = 0;

			if(n == 1){
				lb = 1;
				ub = a;
			}
			else{
				ub = a + (n - 1) * (a - b);
				lb = a + (n - 2) * (a - b) + 1;
			}


			if(ub < l || lb > u){
				cout << "0 ";
			}
			else{
				l  = max(l, lb);
				u =  min(u, ub);
				cout << "1 ";
			}
		}
		else{
			int a, b;
			cin >> a >> b;

			if(u <= a){
				cout << 1 << " ";
				continue;
			}

			int x1 = 0;

			if(l <= a){
				x1 = 0;
			}
			else if(l <= 2 * a - b){
				x1 = 1;
			}
			else{
				x1 = (l - a) / (a - b);
				if((l - a) % (a - b) == 0){
					x1 += 0;
				}
				else{
					x1 += 1;
				}
			}

			int x2 = (u - b - 1) / (a - b) + 1;

 			if(x1 != x2 - 1){
 				cout << "-1 ";
 			}
 			else{
 				cout << x2 << " ";
 			}

		}
	}
	cout << "\n";

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