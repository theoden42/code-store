
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

const int MAX_N = 505;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[505][505];

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> d;
    for(int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	d.push_back(x);
    }
    vector<int> slimits(n);
    for(int i = 0; i < n; i++){
    	cin >> slimits[i];
    }

    for(int i = 0; i < MAX_N; i++){
    	for(int j = 0; j < MAX_N; j++){
            dp[i][j] = INF;
        }
    }

    d.push_back(l);

    for(int i = 0; i <= k; i++){
        dp[n + 1][i] = 0;
    }


    for(int i = n; i >= 1; i--){
    	for(int j = k; j >= 0; j--){
            // how many more can i remove ?
            for(int next = 0; next <= k - j; next++){
                if(i + 1 + next <= n + 1){
                    dp[i][j] = min(dp[i][j], dp[i + 1 + next][j + next] + (d[i + next] - d[i - 1]) * slimits[i - 1]);
                }
            }
    	}
    }



    cout << dp[1][0] << "\n";

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