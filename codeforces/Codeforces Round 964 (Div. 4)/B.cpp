

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
	vector<int> v(2), x(2);
	cin >> v[0] >> v[1] >> x[0] >> x[1];
	sort(all(v));
	int ans = 0;
	for(int ii = 0; ii < 2; ii++){
		for(int jj = 0; jj < 2; jj++){
			if(ii & 1){
				sort(all(v));
			} else {
				sort(all(v));
				reverse(all(v));
			} 
			if(jj & 1){
				sort(all(x));
			} else {
				sort(all(x));
				reverse(all(x));
			}
			int a = 0, b = 0;
			for(int i = 0; i < 2; i++){
				if(v[i] > x[i])
					a += 1;
				else if(v[i] < x[i])
					b += 1;
			}
			if(a > b)
				ans += 1;
		}
	}
	cout << ans << "\n";
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