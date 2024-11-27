

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
	if(n <= 3){
		cout << "-1\n";
	} else {
		int ind = n;
		for(int i = n - 1; i >= 1; i--){
			if(is_prime[i]){
				ind = i;
				break;
			}
		}
		vector<int> ans(n);
		int count = 1;
		for(int i = ind + 1; i <= n; i++){
			ans[i - 1] = count;
			count++;
		}
		for(int i = 1; i <= ind; i += 1){
			ans[i - 1] = count;
			count += 1;
		}
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << "\n";
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