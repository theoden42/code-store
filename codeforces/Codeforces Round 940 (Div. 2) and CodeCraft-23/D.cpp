

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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }

    vector<vector<int>> pre(n + 1, vector<int>(32, 0));
    for(int i = 1; i <= n; i++){
    	pre[i] = pre[i - 1];
    	int v = a[i - 1];
    	for(int j = 0; j < 32; j++){
    		if(v >> j & 1)
    			pre[i][j] += 1;
    	}
    }

    vector<vector<int>> precount(n + 1, vector<int>(32, 0));
    for(int i = 1; i <= n; i++){
    	precount[i] = precount[i - 1];
    	for(int j = 0; j < 32; j++){
    		if(pre[i][j] & 1)
    			precount[i][j] += 1;
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	int b = -1;

    	for(int j = 31; j >= 0; j--){
    		if(a[i] >> j & 1){
    			b = j;
    			break;
    		}
    	}

    	int oddleft = precount[i][b];
    	int oddright = precount[n][b] - oddleft;

    	int evenleft = i + 1 - oddleft;
    	int evenright = (n - i) - oddright;

    	int pair = oddleft * oddright + evenleft * evenright;

    	ans += pair;
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