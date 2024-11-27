

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
const ll MOD = 998244353;
const ll INF = 1e9;

#define int long long

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

ll modinverse(ll a, ll b=MOD){
	return binpow(a, b - 2) % MOD;
}


vector<int> factorial(MAX_N);

void preprocess(){
	factorial[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
}

int ncr(int n, int r){

	if(r > n)return 0;

	int ans = factorial[n];
	ans *= modinverse(factorial[r]);
	ans %= MOD;
	ans *= modinverse(factorial[n - r]);
	ans %= MOD;

	return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int c1 = 0, c2 = 0;

    for(int i = 0; i < n; i++){
    	if(s[i] == '0')continue;

    	int j = i;
    	while(j < n && s[j] == '1'){
    		j++;
    	}

    	int l = (j - i);
    	if(l & 1){
    		c2++;
    		c1 += (j - i - 1);
    	}
    	else{
    		c1 += (j - i);
    	}
    	i = j - 1;
    }

    // debug(c1, c2);
    int pos = n - c1 - c2 + 1;
    int dig = c1 / 2;

    // debug(pos, dig);

    int ans = 0;
    for(int r = 1; r <= dig; r++){
    	int temp = ncr(pos, r);
    	temp *= ncr(dig - 1, r - 1);
    	temp %= MOD;
    	ans += temp;
    	ans %= MOD;
    }

    cout << max(1ll, ans) << "\n";

}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    preprocess();
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}