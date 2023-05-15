
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> ele(n);
	for(int i = 0; i < n; i++){
		cin >> ele[i];
	}
	int sz = 1 << n;
	vector<pair<int,int>> dp(sz, {INF, INF});
	dp[0] = {0, x};

	for(int i = 0; i < sz; i++){
		vector<int> setb;
		int temp = i;

		for(int j = 0; j < n; j++){
			if(!(temp & (1 << j))){
				setb.push_back(j);
			}
		}

		for(int j = 0; j < (int)setb.size(); j++){
			if(dp[i].second + ele[setb[j]] <= x){
				dp[i | (1 << setb[j])] = min(dp[i | (1 << setb[j])], {dp[i].first, dp[i].second + ele[setb[j]]}); 
			}
			else{
				dp[i | (1 << setb[j])] = min(dp[i | (1 << setb[j])], {dp[i].first + 1, ele[setb[j]]});
			}
		}
	}
	cout << dp[sz - 1].first << "\n";

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