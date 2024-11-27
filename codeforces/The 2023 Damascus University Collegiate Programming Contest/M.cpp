

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


vector<int> facs(MAX_N + 1);
vector<int> invfacs(MAX_N + 1);
void preprocess(){
	facs[0] = 1;
	invfacs[0] = modinverse(1);
	for(int i = 1; i <= MAX_N; i++){
		facs[i] = (facs[i - 1] * i) % MOD;
		invfacs[i] = modinverse(facs[i]);
	}
}

int ncr(int n, int r){
	int ans = facs[n];
	ans *= invfacs[r];
	ans %= MOD;
	ans *= invfacs[n - r];
	ans %= MOD;
	return ans;
}


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> s(k);
	for(int i = 0; i < k; i++){
		cin >> s[i];
	}
	sort(all(s));

	// debug(s);

	int ans = 1;
	int left = n;
	int lst = 0;
	for(int i = 0; i < k; i++){
		int num = s[i] - lst;
		ans *= ncr(left, num);
		ans %= MOD;
		left -= num;
		lst = s[i];
	}

	cout << ans << "\n";
}


int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    preprocess();
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}