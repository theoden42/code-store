

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

const int MAX_N = 2e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#define int long long

ll binpow(ll a, ll b=MOD)
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

vector<int> factorial(MAX_N + 1, 1);

void pre(){
	for(int i = 1; i <= MAX_N; i++){
		factorial[i] = (i * factorial[i - 1]) % MOD;
	}
}

int ncr(int n, int r){
	int x = factorial[n];
	x *= modinverse(factorial[n - r]);
	x %= MOD;
	x *= modinverse(factorial[r]);
	x %= MOD;
	return x;
}

void solve() {
	pre();
    int n;	
    cin >> n;
    string s;
    cin >> s;
    int k = s.size();
    int count = 0;
    for(int i = 0; i < k; i++){
    	if(s[i] == '(')
    		count += 1;
    	else 
    		count -= 1;
    	if(count < 0){
    		cout << "0\n";
    		return;
    	}
    }

    int rem = n - k - count;
    if(rem & 1 || rem < ){
    	cout << "0\n";
    	return;
    }	

    rem /= 2;

    int val = ncr(2 * rem + count, rem);
    val *= (count + 1);
    val %= MOD;
    val *= modinverse(rem + count + 1);
    val %= MOD;

    cout << val << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}