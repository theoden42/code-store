#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;
const ll max_m = 1e6 + 5;

vector<ll> fact(max_m, 0);

ll bexp(ll a, ll x, ll mod){
	if(x == 0){
		return 1;
	}
	else if(x % 2 == 1){
		return ((a % mod)* bexp(a, x - 1, mod) % mod) % mod;
	}
	else{
        ll t = (bexp(a, x / 2, mod) % mod);
        return (t * t) % mod; 
	}
}

ll modinv(ll a, ll mod){
	return bexp(a, mod - 2, MOD);
}

ll value(ll n, ll m, ll i){
    ll mcv = 0;
    ll temp = (fact[m - i] * fact[i]) % MOD;
    mcv = (fact[m] * modinv(temp, MOD)) % MOD;
    ll perm = 0;
    temp = (fact[n - i] * fact[i]) % MOD;
    perm = (fact[n] * modinv(temp, MOD)) % MOD;
    ll ans = (mcv * perm) % MOD;
    return ans;
}


void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll v = min(m, k);
    ll sum = 0;
    for(ll i = 1; i <= v; i++){
        sum = sum % MOD + value(n, m, i) % MOD;
    }
    cout << sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    fact[0] = 1;
    for(int i = 1; i < max_m; i++){
    	fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
    }
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}