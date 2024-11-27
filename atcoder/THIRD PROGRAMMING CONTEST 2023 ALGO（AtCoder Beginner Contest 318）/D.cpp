

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

int n;
vector<vector<int>> adj;
vector<int> dp(1 << 17, -1);

int find(int cur){
	if(dp[cur] != -1)
		return dp[cur];

	int mx = 0;
	for(int j = 0; j < n; j++){
		for(int k = j + 1; k < n; k++){
			if((!(cur >> j & 1)) && (!(cur >> k & 1))){
				int temp = cur;
				temp |= (1 << j);
				temp |= (1 << k);
				mx = max(mx, adj[j][k] + find(temp));
			}
		}
	}

	return dp[cur] = mx;
}


void solve() {
    cin >> n;
    adj.resize(n, vector<int> (n));
    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){
    		int x;
    		cin >> x;
    		adj[i][j] = x;
    		adj[j][i] = x;
    	}
    }

    int mx = find(0);
    cout << mx << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}