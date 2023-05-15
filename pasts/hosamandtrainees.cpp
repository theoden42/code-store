
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

const ll MAX_N = 4e4;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;




vector<bool> is_prime(MAX_N + 1, true);
vector<ll> primes;


void sieve(){
    is_prime[1] = is_prime[0] = false;
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
    debug(primes.size());
    int n;
    cin >> n;
    vector<ll> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    set<int> primesfact;

    // now to check all the prime factors of the number here 
    // there must be a prime number x < num which divides the number given ?
    // now how large can x be ?
    // if we think about it> the number num can be said to be like: num = p_1^a * p_2^b * p_3^c...
    // now how large can these prime, be? well as larges as num / 2, but if we think about it...
    // if num / 2 in itself is not a prime number, then it must have atleast a prime factor of num / 4;
    // if we go by this root, we will get the whole prime factorisation by just dividing with twoo..
    // however it still is left to show how large can the primes be,, suppose we have a number which is p1 * p1,, now p1 can be 
    // as large as sqrt(p1)::::: which is what the largest primes factors is:
    /* Hmm so we saw that for a_i = 1e9 we can have prime factors upto 1e5 
    brrr, i knew that already, how to use it to calculate the factors,, i cannot..
    actually the thing is prime density, i get it now, the number of primes less than 1e5 are baout 3500 so its musch easier to factorise with this in mind
    */ 


    for(int i = 0; i < n; i++){
        ll num = ele[i];

        for(auto& x: primes){
            if(x * x > ele[i])break;

            if(ele[i] % x == 0){
                if(primesfact.find(x) != primesfact.end()){
                    cout << "Yes\n";
                    return;
                }
                primesfact.insert(x);
                while((ele[i] % x) == 0){
                    debug(ele[i], x);
                    ele[i] = ele[i] / x;
                }
            }
        }
        if(ele[i] > 1){
            if(primesfact.find(ele[i]) != primesfact.end()){
                cout << "Yes\n";
                return;
            }
            primesfact.insert(ele[i]);
        }
    }


    cout << "No\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    sieve();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}