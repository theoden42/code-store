
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

const ll MOD = 998244353;
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

    ll sum = 0;

    for(int i = 0; i < n; i++){
    	vector<int> digits;
    	int x = ele[i];
    	while(x != 0){
    		digits.push_back(x % 10);
    		x /= 10;
    	}

    	int count = 0;
    	for(auto& x: digits){
    		int val = (x * binpow(10, count)) % MOD;
    		count += 2;
    		sum = (sum + val) % MOD;
    	}

    	count = 1;
    	for(auto& x: digits){
    		int val = (x * binpow(10, count)) % MOD;
    		count += 2;
    		sum = (sum + val) % MOD;
    	}
    }

    cout << (n * sum) % MOD << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}