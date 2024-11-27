

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


int f(int i, int j, vector<vector<int>>& a, int curr, map<vector<int>,int>& mp){
	int n = a.size();
	int m = a[0].size();

	if(mp.find({i, j, curr}) != mp.end())return mp[{i, j, curr}];

	curr += a[i][j];

	if(i == n - 1 && j == m - 1)return (curr == 0);

	int x = 0;
	if(i < n - 1){
		x |= f(i + 1, j , a, curr, mp);
	}
	if(j < m - 1){
		x |= f(i, j + 1, a, curr, mp);
	}

	return x;
}	


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		cin >> a[i][j];
    	}
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1e9));

    dp[0][0] = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + a[i][j]);
            }
            if(j > 0){
                dp[i][j] = max(dp[i][j], dp[i][j - 1] + a[i][j]);
            }
        }
    }

    int mx = dp[n - 1][m - 1];

    dp.resize(n, vector<int>(m, 1e9));
    dp[0][0] = a[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(i > 0){
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i][j]);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i][j]);
            }
        }
    }

    int mn = dp[n - 1][m - 1];

    if((n + m - 1) & 1){
        cout << "No\n";
    }
    else{
        if(mx < 0 || mn > 0){
            cout << "No\n";
        }
        else{
            cout << "Yes\n";
        }
    }

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