
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
const ll INF = 1e9;


int nthdigit(int mx, int ind){
	for(int i = 1; i < ind; i++){
		mx = mx / 10;
	}
	return mx % 10;
}
 
int nod(int mx){
	if(mx == 0) return 1;
 
	int c = 0;
	while(mx != 0){
		c++;
		mx /= 10;
	}
	return c;
}



int f(int ndigits, int nzero, int tight, int bound, vector<vector<vector<int>>>& dp){
	if(ndigits == 1){
		int count = 0;
		int mx = (tight) ? bound % 10 : 9;
		if(nzero < 3){
			return mx + 1;
		}
		return 1;
	}

	if(dp[ndigits][nzero][tight] != -1){
		return dp[ndigits][nzero][tight];
	}

	int count = 0;

	if(nzero == 3){
		count += f(ndigits - 1, nzero, 0, bound, dp);
		return dp[ndigits][nzero][tight] = count;
	}

	int mx = nthdigit(bound, ndigits);

	if(tight){
		if(mx == 0){
			count += f(ndigits - 1, nzero, 1, bound, dp);
		}
		else{
			count += f(ndigits - 1, nzero, 0, bound, dp);
			count += (mx - 1) * f(ndigits - 1, nzero + 1, 0, bound, dp);
			count += f(ndigits - 1, nzero + 1, 1, bound, dp);
		}

		return dp[ndigits][nzero][tight] = count;
	}

	else{
		count += f(ndigits - 1, nzero, 0, bound, dp);
		count += 9 * f(ndigits - 1, nzero + 1, 0, bound, dp);
		return dp[ndigits][nzero][tight] = count;
	}
}	

void solve() {
    int l, r;
    cin >> l >> r;

    vector<vector<vector<int>>> dp(21, vector<vector<int>>(4, vector<int>(2, -1)));
    int ans = f(nod(r), 0, 1, r, dp);
    dp.assign(sizeof(dp), vector<vector<int>>(4, vector<int>(2, -1)));
    debug(ans);
    ans -= f(nod(l - 1),0, 1, l - 1, dp);
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