
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
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;	
    cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; i++){
    	int a, b, h;
    	cin >> a >> b >> h;
    	v[i] = {b, a,  h};
    }

    sort(v.begin(), v.end());

    debug(v);
    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    for(int i = 1; i <= n; i++){

    	int b = v[i - 1][0];
    	int a = v[i - 1][1];
    	int h = v[i - 1][2];

        int l = 0;
        int u = i - 2;
    	int ind = 0;


    	while(l <= u){
    		int mid = l + (u - l) / 2;
    		if(v[mid][0] > a){
    			ind = mid;
                l = mid + 1;
    		}
    		else{
                u = mid - 1;
    		}
    	}

        debug(i, ind);

    	dp[i] = max(dp[i - 1], h + dp[ind + 1]);

    }

    debug(dp);

    cout << dp[n] << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}