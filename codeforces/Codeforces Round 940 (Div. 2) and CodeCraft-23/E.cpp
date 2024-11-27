

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

#define int long long

vector<int> ans(MAX_N + 1);

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

void pre(){
	sieve(); 

	for(int n = 1; n < MAX_N; n++){
		if(!is_prime[n] && n != 4)
			continue;
		int rem = (n == 4) ? 2 : n - 1;
		for(int k = 1; k * n < MAX_N; k++){
			int left = n * k;
			int right = min((ll)MAX_N, n * (k + 1));
			int value = (k * rem) % n;

			ans[left] += value;
			ans[left] %= MOD;

			ans[right] -= value;
			ans[right] += MOD;
			ans[right] %= MOD;
		}
	}

	for(int i = 1; i < MAX_N; i++){
		ans[i] += ans[i - 1];
		ans[i] %= MOD;
	}

	for(int i = 1; i < MAX_N; i++){
		ans[i] += ans[i - 1];
		ans[i] %= MOD;
	}
}


void solve() {
	int n;
	cin >> n;
	cout << ans[n] << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    pre();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}