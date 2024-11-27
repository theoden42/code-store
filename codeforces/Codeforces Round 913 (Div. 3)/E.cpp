

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

// int sod(int t){
// 	int s = 0;
// 	while(t != 0){
// 		s += t % 10;bgbgg
// 		t /= 10;
// 	}
// 	return s;
// }
		

void solve() {	
	int n;
	cin >> n;
	int ans = 1;
	for(int i = 0; i < 8 && n != 0; i++){
		set<vector<int>> st;
		int dig = n % 10;
		for(int j = 0; j <= 9; j++){
			for(int k = 0; k <= 9; k++){
				for(int l = 0; l <= 9; l++){
					if(j + k + l < 10 && j + k + l == dig){
						st.insert({j, k, l});
					}
				}
			}
		}
		// debug(ans, st);
		ans *= (int)st.size();
		n /= 10;
		debug(n);
	}
	debug(n);
	debug(ans);
	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << t << ": "; 
        solve();
    }
}