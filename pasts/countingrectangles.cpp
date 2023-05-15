
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
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> rec(1005, vector<ll>(1005, 0));

    for(int i = 0; i < n; i++){
    	ll x, y;
    	cin >> x >> y;
    	rec[x][y] += (x * y);
    }

    vector<vector<ll>> prefix(1005, vector<ll>(1005, 0));
    prefix[0][0] = rec[0][0];
    for(int i = 1; i < 1005; i++){
    	prefix[i][0] = prefix[i - 1][0] + rec[i][0];
    }
    for(int j = 1; j < 1005; j++){
    	prefix[0][j] = prefix[0][j - 1] + rec[0][j];
    }

    for(int i = 1; i < 1005; i++){
    	for(int j = 1; j < 1005; j++){
    		prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + rec[i][j];
    	}
    }
    // for(int i = 0; i <= 10; i++){
    // 	for(int j = 0; j <= 10; j++){
    // 		cout << prefix[i][j] << " ";
    // 	}
    // 	cout << "\n";
    // }

    for(int i = 1; i <= q; i++){
    	int hs, ws, hb, wb;
    	cin >> hs >> ws >> hb >> wb;
    	debug(prefix[hb - 1][wb - 1]);
        debug(prefix[hb][ws], prefix[hs][wb]);
        ll ans = prefix[hb - 1][wb - 1] - prefix[hb - 1][ws] - prefix[hs][wb - 1] + prefix[hs][ws];
    	cout << ans << "\n";
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