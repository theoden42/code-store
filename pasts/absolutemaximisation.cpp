
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

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    debug(ele);
    int mn = 0;
    int mx = 0;

    for(int i = 0; i < 11; i++){
    	int count = 0;
    	for(int j = 0; j < n; j++){
    		if(ele[j] & 1){
    			count++;
    		}
    		ele[j] >>= 1;
    	}
    	debug(count);
    	if(count == n){
    		mn += binpow(2, i);
    		mx += binpow(2, i);
    	}
    	else if(count > 0){
    		mx += binpow(2, i);
    	}
    }
    debug(mx, mn);
    cout << mx - mn << "\n";
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