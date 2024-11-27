

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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    }

   	vector<int> count(n);
   	map<char,int> mp = {{'n', 0}, {'a', 1}, {'r', 2}, {'e', 3}, {'k', 4}};
   	vector<vector<pair<int,int>>> start(n, vector<pair<int,int>>(5));
   	for(int i = 0; i < n; i++){
   		int cnt = 0;
   		for(int j = 0; j < m; j++){
   			if(mp.find(s[i][j]) != mp.end()){
   				cnt += 1;
   			}
   		}
   		count[i] = cnt;
   		for(int curr = 0; curr < 5; curr++){
   			int temp = curr;
   			int wrdcnt = 0;
   			for(int j = 0; j < m; j++){
   				if(mp.find(s[i][j]) != mp.end() && mp[s[i][j]] == temp){
   					temp += 1;
   					temp %= 5;
   					if(temp == 0){
   						wrdcnt += 1;
   					}
   				}
   			}
   			start[i][curr] = make_pair(wrdcnt, temp);
   		}
   	}

   	vector<vector<int>> dp(n + 1, vector<int>(5, -1e18));
   	dp[0][0] = 0;
   	for(int i = 1; i <= n; i++){
		for(int k = 0; k < 5; k++){
			if(dp[i - 1][k] == -1e18)
				continue;
			auto [wrdnt, end] = start[i - 1][k];
			dp[i][k] = max(dp[i][k], dp[i - 1][k]);
			int val = 10 * wrdnt - count[i - 1]; 
			dp[i][end] = max(dp[i][end], dp[i - 1][k] + val);
		}
   	}
   	int ans = 0;
   	for(int i = 0; i < 5; i++){
   		ans = max(ans, dp[n][i]);
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