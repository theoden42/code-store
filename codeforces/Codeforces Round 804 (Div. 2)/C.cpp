

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

int getstep(int zero, int one){
	return ((zero < one) ? 1 : -1);
}



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

void pre(){
	factorial[0] = 1;
	for(int i = 1; i < MAX_N; i++){
		factorial[i] = (factorial[i - 1] * i) % MOD;
	}
}

int ncr(int n, int r){
	if(n == 0 || r == 0)return 1;
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
	vector<int> a(n);
	map<int,int> mp;
	int zero = 0;
	int one = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] == 0)zero = i;
		mp[a[i]] = i;
	}

	int l = zero;
	int r = zero;
	int mx = 1;

	int ans = 1;
	set<int> st;
	int spaces = 0;

	while(mx != n){
		int pos = mp[mx];
		if(pos > r){
			for(int i = r + 1; i <= pos; i++){
				st.insert(a[i]);
			}
			spaces += pos - r - 1;
			r = pos;
		}
		else{
			for(int i = l - 1; i >= pos; i--){
				st.insert(a[i]);
			}
			spaces += l - pos - 1;
			l = pos;
		}

		int lmx = mx;
		while(st.find(mx) != st.end()){
			mx++;
		}

		int nw = mx - lmx - 1;
		ans *= ncr(spaces, nw);
		ans %= MOD;
		ans *= factorial[nw];
		ans %= MOD;
		spaces -= nw;
	}

	cout << ans << "\n";

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