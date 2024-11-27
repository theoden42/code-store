

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
    int n;
    cin >> n;
    vector<int> valx(n + 1), valy(n + 1);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	if(y == 0)
    		valx[x] += 1;
    	else 
    		valy[x] += 1;
    }

    int ans = 0;
    for(int i = 0; i <= n; i++){
    	if(valx[i] == 1 && valy[i] == 1){
    		ans += (n - 2);
    	}
    }
    for(int x = 1; x < n; x++){
    	if(valx[x] == 1 && valy[x - 1] == 1 && valy[x + 1] == 1)
    		ans += 1;
    }
    for(int y = 1; y < n; y++){
    	if(valy[y] == 1 && valx[y - 1] == 1 && valx[y + 1] == 1)
    		ans += 1;
    }

   	cout << ans << "\n";
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