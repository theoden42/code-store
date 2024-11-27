
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define int long long
#define ld long double
#define ll long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 2e7 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;


void sieve(){
	is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }

    for(ll i = 1; i <= MAX_N; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }
}



void solve() {
    int n;
    cin >> n;
    for(int i = 2; i <= 2e7; i++){
    	if(!is_prime[i])continue;
   		int val = i * i;
   		if(n % val == 0){
   			cout << i << " " << n / val << "\n";
   			return;
   		}
   		if(n % i == 0){
   			cout << (int)sqrtl(n / i) << " " << i << "\n";
   			return;
   		}
    }
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