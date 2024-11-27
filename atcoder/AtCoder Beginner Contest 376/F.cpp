

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
    int n, q;
    cin >> n >> q;
   	vector<vector<int>> dp(q + 1, vector<int>(n, 1e18));
   	dp[0][1] = 0;
   	vector<int> lst(q + 1), hnd(q + 1);
   	lst[0] = 0;
   	hnd[0] = 0;
   	for(int i = 1; i <= q; i++){
   		char c;int x;
   		cin >> c >> x;
   		x -= 1;
   		lst[i] = x;
   		hnd[i] = (c == 'L') ? 0 : 1;
   	}

   	for(int i = 1; i <= q; i++){
   		for(int j = 0; j < n; j++) if(dp[i - 1][j] != 1e18){
   			int l, r;
   			if(hnd[i - 1]){
   				l = j;
   				r = lst[i - 1];
   			} else {
   				l = lst[i - 1];
   				r = j;
   			}
   			if(!hnd[i]){
   				swap(l, r);
   			}
			int x = lst[i];
			if(x >= r){
				int cstplus = 0, cstminus = 0;
				if(l >= r && l <= x){
					cstplus += (x - r + n) % n;
					cstplus += ((x + 1) % n - l + n) % n;
					cstminus += (r - x + n) % n;
					dp[i][(x + 1) % n] = min(dp[i][(x + 1) % n], dp[i - 1][j] + cstplus);
					dp[i][l] = min(dp[i][l], dp[i - 1][j] + cstminus);
				} else {
					cstplus += (x - r + n) % n;
					cstminus += (r - x + n) % n;
					cstminus += (l - (x - 1 + n) % n + n) % n;
					dp[i][l] = min(dp[i][l], dp[i - 1][j] + cstplus);
					dp[i][(x - 1 + n) % n] = min(dp[i][(x - 1 + n) % n], dp[i - 1][j] + cstminus);
				}
			} else {
				int cstplus = 0, cstminus = 0;
				if(l >= x && l <= r){
					cstplus = (x - r + n) % n;
					dp[i][l] = min(dp[i][l], dp[i - 1][j] + cstplus); 
					cstminus = (r - x + n) % n;
					cstminus += (l - (x - 1 + n) % n + n) % n;
					dp[i][(x - 1 + n) % n] = min(dp[i][(x + n - 1) % n], dp[i - 1][j] + cstminus);
				} else {
					cstplus = (x - r + n) % n;
					cstplus += ((x + 1) % n - l + n) % n;
					dp[i][(x + 1) % n] = min(dp[i][(x + 1) % n], dp[i - 1][j] + cstplus);
					cstminus = (r - x + n) % n;
					dp[i][l] = min(dp[i][l], dp[i - 1][j] + cstminus);
				}
			}
   		}
   	}
   	int val = 1e18;
   	for(int i = 0; i < n; i++){
   		val = min(val, dp[q][i]);
   	}
   	cout << val << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}