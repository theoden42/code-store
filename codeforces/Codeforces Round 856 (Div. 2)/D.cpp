
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


vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;
int fac[MAX_N];


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

ll modinverse(ll a){
	return binpow(a, MOD - 2) % MOD;
}


void preprocess(){
    fac[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		fac[i] = (fac[i - 1] * i) % MOD;
	}
}


void sieve(){
	is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}



void solve() {
    int n;
    cin >> n;
    vector<int> ele(2 * n);
    map<int,int> mp;

    for(int i = 0; i < 2 * n; i++){
    	cin >> ele[i];
    	mp[ele[i]]++;
    }

    int ans = fac[n];
    debug(fac[n]);
    vector<int> primes;

    for(auto& x: mp){
    	int p = x.first;
    	int t = x.second;
    	if(!is_prime[p]){
    		ans = (ans * modinverse(fac[t])) % MOD;
    	}
    	else{
    		primes.push_back(p);
    	}
    }


    int len = primes.size();
    vector<vector<int>> dp(len + 1, vector<int>(n + 1));


    // first with base cases let's see, how can i pick up 
    dp[len][n] = 1;
    for(int i = 0; i < n; i++){
        dp[len][i] = 0;
    }

    for(int i = len - 1; i >= 0; i--){
        for(int j = n; j >= 0; j--){
            if(j != n){
                 dp[i][j] = ((dp[i + 1][j] * modinverse(fac[mp[primes[i]]])) % MOD + (dp[i + 1][j + 1] * modinverse(fac[mp[primes[i]] - 1])) % MOD) % MOD;
            }
            else{
                dp[i][j] = (dp[i + 1][j] * modinverse(fac[mp[primes[i]]])) % MOD;
            }
           
        }
    }

    ans = (ans * dp[0][0]) % MOD;
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    sieve();
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}
