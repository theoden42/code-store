
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

ll binpow(ll a, ll b)
{
    ll ans = 1;
    while(b){
        if(b & 1){
        	ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        b = b >> 1; 
    }
    return (ans % MOD);
}

void solve() {
    int n;
    cin >> n;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> ans(n, 0);
    ans[0] = 0;
    for(int i = 1; i < n; i++){
    	int as = 0;
    	for(int j = 0; j < 32; j++){
    		int ch1 = (ele[i - 1] & (1 << j)) == 0 ? 0: 1;
    		int ch2 = (ele[i] & (1 << j)) == 0 ? 0: 1;
    		debug(j, ch1, ch2);
    		if(ch1 == 1 && ch2 == 0){
    			as += binpow(2, j);
    		}
    	}
    	ele[i] = (ele[i] ^ as);
    	ans[i] = as;
    }
    for(auto& x: ans){
    	cout << x << " ";
    }
    cout << "\n";
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