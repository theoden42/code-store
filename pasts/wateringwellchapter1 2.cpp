
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll int64_t
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    ll n, q;
    cin >> n;
    vector<pair<ll,ll>> trees(n);
    for(int i = 0; i < n; i++){
    	ll x, y;
    	cin >> x >> y;
    	trees[i] = {x, y};
    }
    cin >> q;
    vector<pair<ll,ll>> wells(q);
    for(int i = 0; i < q; i++){
    	ll x, y;
    	cin >> x >> y;
    	wells[i] = {x, y};
    }
    ll sumsquaresx = 0;
    ll sumsquaresy = 0;
    ll sumx = 0;
    ll sumy = 0;
    ll ans = 0;

    // debug(n, q);
    // debug(trees);
    // debug(wells);
    for(int i = 0; i < n; i++){
    	sumsquaresx = (sumsquaresx + (trees[i].first * trees[i].first) % MOD) % MOD;
    	sumsquaresy = (sumsquaresy + (trees[i].second * trees[i].second) % MOD) % MOD;
    	sumx = (sumx + trees[i].first) % MOD;
    	sumy = (sumy + trees[i].second) % MOD;
    }
    for(int i = 0; i < q; i++){
    	ans = (ans + sumsquaresx) % MOD;
    	ans = (ans + sumsquaresy) % MOD;
    	ans = (ans + (n * ((wells[i].first * wells[i].first) % MOD)) % MOD) % MOD;
    	ans = (ans + (n * ((wells[i].second * wells[i].second) % MOD)) % MOD) % MOD;
    	ans = (ans - (2 * ((wells[i].first * sumx) % MOD)) % MOD + MOD) % MOD;
    	ans = (ans - (2 * ((wells[i].second * sumy) % MOD)) % MOD + MOD) % MOD;
    }
    cout << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}