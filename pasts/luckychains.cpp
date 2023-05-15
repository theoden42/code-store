
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

const int MAX_N = 1e7 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;



vector<bool> is_prime(MAX_N + 1, true);

vector<ll> spf(MAX_N + 1, -1);


void sieve(){
	is_prime[0] = is_prime[1] = false;
	spf[0] = 0;
	spf[1] = 1;
	spf[2] = 2;

	for(int i = 2; i <= MAX_N; i++){
		spf[i] = i;
	}

    for (ll i = 2; i * i <= MAX_N; i++) {
        if(is_prime[i]) {
        	spf[i] = i;
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
	int x, y;
	cin >> x >> y;
	int val = y - x;
	if(val == 1){
		cout << "-1\n";
		return;
	}

	// counting factors of val
	int mx = val - x % val;

	debug(val);

	while(val != 1){
		int sf = spf[val];
		debug(sf);

		if(x % sf == 0){
			mx = 0;
		}
		else{
			mx = min(mx, sf - x % sf);
		}

		debug(sf, mx);

		while(val % sf == 0){
			val /= sf;
		}
	}

	cout << mx << "\n";

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