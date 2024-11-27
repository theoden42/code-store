

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
    vector<int> v(n);
    for(int i = 0; i < n; i++){
    	cin >> v[i];
    }
    vector<vector<int>> sm(n + 1, vector<int> (n + 1, 0));

    for(int i = 1; i <= n; i++){
    	int k = v[i - 1];
    	for(int j = 1; j < i; j++){
    		int x = v[j - 1];
    		if(k > x){
    			sm[j][i] = sm[j - 1][i] + 1;
    		}
    		else{
    			sm[j][i] = sm[j - 1][i];
    		}
    	}
    }

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		sm[i][j] = sm[i][j] + sm[i][j - 1];
    	}
    }

    // debug(sm);

    ll count = 0;

    for(int b = 1; b < n; b++){
    	for(int d = b + 2; d < n; d++){
    		if(v[b] < v[d])continue;

    		int s = sm[b][d] - sm[b][b + 1];

    		// debug(v[b], v[d], s, sm[b + 1][d + 1], sm[b + 1][b + 1]);

    		count += s;
    	}
    }

    cout << count << "\n";

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