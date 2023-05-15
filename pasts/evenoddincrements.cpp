
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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

   	ll sum = 0;
   	int nodd = 0;
   	int neven = 0;
   	for(int i = 0; i < n; i++){
   		sum += ele[i];
   		if(ele[i] % 2 == 1){
   			nodd++;
   		}
   		else{
   			neven++;
   		}
   	}

    for(int i = 1; i <= q; i++){
    	ll t, x;
    	cin >> t >> x;
    	if(t == 0){
    		sum += 1ll * neven * x;
    		if(x % 2 != 0){
    			nodd += neven;
    			neven = 0;
    		}
    	}
    	else{
    		sum += 1ll * nodd * x;
    		if(x % 2 != 0){
    			neven += nodd;
    			nodd = 0;
    		}
    	}
    	cout << sum << "\n";
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