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

vector<ll> fact(16,1);

int countbit(ll a){
	int count = 0;
	while( a != 0){
		if((a & 1ll) == 1ll){
			count++;
		}
		a = (a >> 1ll);
	}
	return count;
}

void solve() {
	ll n; 
	cin >> n;
	int ans = countbit(n);
	ll y = 0;
	for(int i = 0; i <= (1 << 15); i++){
		int count = 0;
		ll sum = 0;
		int x = i;
		int j = 0;
		while(x != 0){
			if((x & 1) == 1){
				sum += fact[j];
				count++;
			}
			x = x >> 1;
			j++;
		}
		if(sum > n){
			continue;
		}
		else{
			ans = min(ans, count + countbit(n - sum));
		}
	}
	cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    for(ll i = 1; i < 16; i++){
    	fact[i] = fact[i - 1] * i;
    }
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}