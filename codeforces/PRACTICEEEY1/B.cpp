

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

const int MAX_N = 1e5 + 5;
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

int get_count(int a){
	int count = 0;
	for(int i = 0; i < primes.size(); i++){
		while(a % primes[i] == 0){
			count++;
			a /= primes[i];
		}
	}
	if(a != 1){
		count++;
	}
	return count;	
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 1){
    	if(a == 1 && b == 1){
    		cout << "NO\n";
    		return;
    	} else if(max(a, b) % min(a, b) == 0 && a != b){
    		cout << "YES\n";
    		return;
    	}
    	else{
    		cout << "NO\n";
    	}
    }
    else{
    	int gc = get_count(a);
    	gc += get_count(b);
    	if(gc >= k){
    		cout << "YES\n";
    	} else {
    		cout << "NO\n";	
    	}
    }

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