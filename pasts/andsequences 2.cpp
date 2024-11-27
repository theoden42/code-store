
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

    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    int andd = ele[0];
    for(int i = 1; i < n; i++){
    	andd = (ele[i] & andd);
    }
    debug(andd);
    ll count = 0;
    for(int i = 0; i < n; i++){
    	if(andd == ele[i])count++;
    }

    if(count < 2){
    	cout << 0 << "\n";
    	return;
    }

    ll ans = 1;
    for(int i = 1; i <= n - 2; i++){
    	ans = (ans * i) % MOD;
    }
    ans = (ans * ((count * (count - 1)) % MOD)) % MOD;
    cout << ans << "\n";
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