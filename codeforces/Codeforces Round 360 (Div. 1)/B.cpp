

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



void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}

	map<int,int> mp;

	for(int i = 2; i * i <= k; i++){
		if(k % i != 0)continue;

		int count = 0;
		while(k % i == 0){
			k /= i;
			count++;
		}
		mp[i] = count;
	}
	if(k != 1){
		mp[k] = 1;
	}

	debug(mp);

	for(int i = 0; i < n; i++){
		while(c[i] != 1){
			int x = spf[c[i]];
			int count = 0;
			while(c[i] % x == 0){
				c[i] /= x;
				count++;
			}
			if(mp[x] <= count){
				mp[x] = 0;
			}
		}
	}

	debug(mp);

	int f = 1;
	for(auto x: mp){
		if(x.second != 0){
			f = 0;
			break;
		}
	}

	if(f)cout << "YES\n";
	else cout << "NO\n";

}


int main() {
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