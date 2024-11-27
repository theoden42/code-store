
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
const ll MOD = 1e10 + 7;
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
    int n, k;
    cin >> n >> k;
    k++;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }



    ll sum = 0;
    for(int i = 0; i < n; i++){
    	if(i != n - 1){
    		int v = min(k, binpow(10, a[i + 1] - a[i]) - 1);
    		k -= v;
    		sum += v * binpow(10, a[i]);
    	}
    	else{
    		int v = k;
    		k -= v;
    		sum += v * binpow(10, a[i]);
    	}

    }
    cout << sum << "\n";
    
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