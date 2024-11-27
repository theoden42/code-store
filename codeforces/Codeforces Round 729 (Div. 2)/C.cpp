

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


#define int long long

const int MAX_N = 500 + 5;
const ll mod = 1e9 + 7;
const ll INF = 1e9;

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


vector<int> prs;

void solve() {
    int n;
    cin >> n;
    int l = 1;
    int ind = 0;
    int ans = 0;

    while(n != 0 && l <= 1e18){
    	int sv = l;
    	int div = prs[ind++];
    	int k = div / gcd(sv, div) - 1;
    	int count = (n / (k + 1));

    	ans += (((n - count + mod) % mod) * div) % mod;
    	ans %= mod;
    	n = count;
    	l = lcm(l, div);
    }

    cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;

    sieve();
    for(int j = 2; j <= 200; j++){
    	vector<int> factors = factorise(j);
    	if(factors.size() == 1){
    		prs.push_back(j);
    	}
    }

    for (int t = 1; t <= tc; t++) {
        solve();
    }
}