
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    	mp[ele[i]] += 1;
    }

    ll count = 0;

    for(auto& x: mp){
    	ll tmx = x.first;
    	ll ctemp = 0;
    	ctemp += 1ll * mp[tmx] * mp[tmx - 1] * mp[tmx - 2];
    	ctemp += 1ll * mp[tmx] * (1ll * mp[tmx - 2] * (mp[tmx - 2] - 1)) / 2;
    	ctemp += 1ll * (mp[tmx] * (mp[tmx] - 1))/2 * mp[tmx - 2];
    	ctemp += 1ll * (mp[tmx] * (mp[tmx] - 1))/2 * mp[tmx - 1];
    	ctemp += 1ll * mp[tmx] * (1ll * mp[tmx - 1] * (mp[tmx - 1] - 1)) / 2;
    	ctemp += 1ll * ((mp[tmx] - 1) * mp[tmx] * (mp[tmx] - 2))/ 6;
    	count += ctemp;
    }

    cout << count << "\n";
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