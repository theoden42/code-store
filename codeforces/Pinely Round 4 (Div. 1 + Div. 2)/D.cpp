

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

const int MAX_N = 2e5 + 5;
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
	if(n == 1){
		cout << 1 << "\n";
		cout << 1 << "\n";
	} else if(n == 2){
		cout << 2 << "\n";
		cout << "1 2\n";
	} else if(n == 3){
		cout << 2 << "\n";
		cout << "1 2 2\n";	
	} else if(n == 4){
		cout << "3\n";
		cout << "1 2 2 3\n";
	} else if(n == 5){
		cout << "3\n";
		cout << "1 2 2 3 3\n";
	} else {
		cout << "4\n";
		for(int i = 1; i <= n; i++){
			cout << (i % 4) + 1 << " \n"[i == n];
		}
	}
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