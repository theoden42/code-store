

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
vector<int> fac(17, 1);

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

ll modinverse(ll a, ll b = MOD){
	return binpow(a, b - 2) % MOD;
}


void preprocess(){
	fac[0] = 1;
	for(int i = 1; i <= 16; i++){
		fac[i] = (fac[i - 1] * i) % MOD;
	}
}

int npr(int n, int r){
	if(r > n || r < 0)return 0;
	int temp = (fac[n] * modinverse(fac[n - r])) % MOD;
	return temp % MOD;
}


void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	set<int> st;
	for(int i = 0; i < n; i++){
		if(s[i] >= 'a' && s[i] <= 'f'){
			st.insert(s[i] - 'a' + 10);
		}
		else{
			st.insert(s[i] - '0');
		}
	}

	int count = 0;
	for(auto x: st){
		if(!(x & 1)){
			count++;
		}
	}

		
	n = st.size();
	if(st.find(0) == st.end()){
		int ans = 0;
		for(int i = 1; i <= n; i++){
			ans = (ans + (count * npr(n - 1, i - 1)) % MOD) % MOD; 
		}
		cout << ans << "\n";
	}
	else{
		int ans = count - 1;
		debug(ans);

		for(int i = 2; i <= n; i++){
			int temp  = 1;
			temp = ((i - 2) * (((count - 1) * npr(n - 2, i - 2)) % MOD)) % MOD;
			debug(temp);
			ans += temp;
			ans %= MOD;
			temp = npr(n - 1, i - 1) % MOD;
			debug(temp);
			ans += temp;
			ans %= MOD;
			temp = ((count - 1) * npr(n - 2, i - 1)) % MOD;
			ans += temp;
			ans %= MOD;

			debug(ans);
		}

		cout << ans << "\n";
	}



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