
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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

ll modinverse(ll a, ll b){
	return binpow(a, b - 2) % MOD;
}


ll calculatemod(ll c, ll m){
	if(c < m)return 0;

	ll fac = 1;
	for(int i = 1; i <= m; i++){
		fac = (fac * i) % MOD;
	}

	ll num = 1;
	for(int i = c; i >= c - m + 1; i--){
		num = (num * i) % MOD;
	}

	return num * modinverse(fac, MOD);

}



void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    sort(all(ele));

    debug(ele);

    ll count = 0;

    for(int i = 0; i < n; i++){
    	auto l = lower_bound(all(ele), ele[i] - k);
    	if(l == ele.end())continue;
    	ll c = i - (l - ele.begin()) + 1;	
    	count = (count + calculatemod(c - 1, m - 1)) % MOD;
    }

    cout << count << "\n";

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