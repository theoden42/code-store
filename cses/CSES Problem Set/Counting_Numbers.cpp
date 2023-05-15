
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define int long long
#define ll long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int dp[21][11][2];

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

int solve(int ndigits, int lastdigit, int tight, int max) {
	if(ndigits == 1){
		int count = 0;
		int mx = (tight) ? max % 10: 9;
		for(int i = 0; i <= mx; i++){
			if(i != lastdigit){
				count++;
			}
		}
		return count;
	}


	if(dp[ndigits][lastdigit][tight] != -1)return dp[ndigits][lastdigit][tight];


	int ans = 0;

	int mx_digit = nthdigit(max, ndigits);
	int mx = (tight) ? mx_digit : 9;


	for(int i = 0; i <= mx; i++){
		if(i != lastdigit){
			int ld = i;
			if(i == 0 && lastdigit == 10){
				ld = 10;
			}

			if(tight && i < mx_digit)
				ans += solve(ndigits - 1, ld, 0, max);
			else if(tight && i == mx_digit)
				ans += solve(ndigits - 1, ld, 1, max);
			else if(tight && i > mx_digit)
				continue;
			else if(!tight)
				ans += solve(ndigits - 1, ld, 0, max);
		}
	}

	return dp[ndigits][lastdigit][tight] = ans;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;

    int a, b;
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    int ans = solve(nod(b), 10, 1, b);

    memset(dp, -1, sizeof(dp));
    if(a != 0)
    	ans -= solve(nod(a - 1), 10, 1, a - 1);

    cout << ans << "\n";
}