

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

int get(string s){

	int n = s.size();	
	vector<vector<int>> dp(n + 1, vector<int>(4, 0));

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++){
			dp[i][j] = 0;
		}
	}

	dp[0][0] = 1;

	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 4; j++)
			dp[i][j] = dp[i - 1][j];

		char ch = s[i - 1];
		if(ch == '4'){
			dp[i][3] += dp[i - 1][2];
			dp[i][3] %= MOD;
			dp[i][1] += 1;
			dp[i][1] %= MOD;
		}
		else{
			dp[i][2] += dp[i - 1][1];
			dp[i][2] %= MOD;
		}
	}

	return dp[n][3];
}

void recur(int ind, string& s, string& temp, int& ans){
	int n = s.size();
	if(ind == n){
		ans += get(temp);
		ans %= MOD;
		return;
	}

	if(s[ind] == '4' || s[ind] == '0'){
		temp += s[ind];
		recur(ind + 1, s, temp, ans);
		temp.pop_back();
	}
	else{
		temp += '4';
		recur(ind + 1, s, temp, ans);
		temp.pop_back();

		temp += '0';
		recur(ind + 1, s, temp , ans);
		temp.pop_back();
	}	

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string temp = "";
    int ans = 0;
    recur(0, s, temp, ans);
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