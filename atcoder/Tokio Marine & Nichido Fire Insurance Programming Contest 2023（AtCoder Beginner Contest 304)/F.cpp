

/* author: (g)theoden42 */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define all(a) a.begin(), a.end()
#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

template<typename T>
using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll =  long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAX_N = 1e6 + 5;
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

vector<bool> is_prime(MAX_N + 1, true);;
vector<int> spf(MAX_N + 1);

void sieve(){
	is_prime[0] = is_prime[1] = false;
    spf[0] = 0;
    spf[1] = 1;
    
    for(int i = 2; i <= MAX_N; i++){
        spf[i] = i;
    }

    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i){
                is_prime[j] = false;
                if(spf[j] == j){
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> factorise(int n){
    vector<int> factors;
    while(n != 1){
        int sf = spf[n];
        factors.push_back(sf);
        while(n % sf == 0){
            n /= sf;
        }
    }
    return factors;
}

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    vector<int> pos;	
    for(int i = 1; i <= (int)x.size(); i++){
    	if(x[i - 1] == '.')pos.push_back(i);
    }

    vector<int> dp(n + 1, 0);

    int ans = 0;

    function<int(int)> countways 
    = [&](int factor)->int{ 

        set<int> st;
        for(auto p: pos){
            st.insert(p % factor);
        }

        int a = binpow(2, factor - st.size());
        return a;
    };

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            dp[i] = countways(i);
            for(int j = 1; j < i; j++){
                if(i % j == 0){
                    dp[i] += (-dp[j] + MOD);
                    dp[i] %= MOD;
                }
            }
            ans += dp[i];
            ans %= MOD;
        }
    }

    cout << ans << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    sieve();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}