
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

ll countnum(vector<int>& a, vector<int>& b, vector<int>& c, int ai, int bi, int ci, vector<vector<vector<int>>>& dp){
	// i take the number cii
	if(ai == 0){
		int f1 = 0;
		int f2 = 0;
		for(int i = 0; i <= bi; i++){
			if(b[i] == a[ai]){
				f1 = 1;
				break;
			}
		}
		for(int i = 0; i <= ci; i++){
			if(c[i] == a[ai]){
				f2 = 1;
				break;
			}
		}
		if(f1 & f2)dp[ai][bi][ci] = 1;
		else dp[ai][bi][ci] = 1;
		return dp[ai][bi][ci];
	}
	else if(bi == 0){
		int f1 = 0;
		int f2 = 0;
		for(int i = 0; i <= ai; i++){
			if(a[i] == b[bi]){
				f1 = 1;
				break;
			}
		}
		for(int i = 0; i <= ci; i++){
			if(c[i] == b[bi]){
				f2 = 1;
				break;
			}
		}
		if(f1 & f2)dp[ai][bi][ci] = 1;
		else dp[ai][bi][ci] = 1;
		return dp[ai][bi][ci];
	}

	else if(ci == 0){
		int f1 = 0;
		int f2 = 0;
		for(int i = 0; i <= bi; i++){
			if(b[i] == c[ci]){
				f1 = 1;
				break;
			}
		}
		for(int i = 0; i <= ai; i++){
			if(a[i] == c[ci]){
				f2 = 1; 
				break;
			}
		}
		if(f1 & f2)dp[ai][bi][ci] = 1;
		else dp[ai][bi][ci] = 1;
		return dp[ai][bi][ci];
	}

	dp[ai][bi][ci] = 0;
	dp[ai][bi][ci] = (dp[ai][bi][ci] + countnum(a, b, c, ai - 1, bi, ci, dp)) % MOD;
	dp[ai][bi][ci] = (dp[ai][bi][ci] + countnum(a, b, c, ai, bi - 1, ci, dp)) % MOD;
	dp[ai][bi][ci] = (dp[ai][bi][ci] + countnum(a, b, c, ai, bi, ci - 1, dp)) % MOD;
	dp[ai][bi][ci] = (dp[ai][bi][ci] + countnum(a, b, c, ai - 1, bi - 1, ci - 1, dp)) % MOD;
	return dp[ai][bi][ci];
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> c[i];
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
    cout << countnum(a, b, c, n - 1, n - 1, n - 1, dp) << "\n";

    
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}