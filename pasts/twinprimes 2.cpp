
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

const int MAX_N = 2e7 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<pair<int,int>> twinprimes;

vector<bool> is_prime(MAX_N + 1, true);


void sieve(){
	is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i * i <= MAX_N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }
}


void preprocess(){

	for(int i = 3; i <= 2e7; i++){
		if(is_prime[i] && is_prime[i + 2]){
			twinprimes.push_back({i, i + 2});
		}
	}
	cerr << twinprimes.size() << "\n";

}

void solve() {
    int t;
    while(cin >> t){
    	cout << "(" << twinprimes[t - 1].first << ", " << twinprimes[t - 1].second << ")" << "\n";
    }
}

int main() {
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