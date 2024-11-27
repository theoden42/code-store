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
const ld EPS = 1e-9;
const ll INF = 2e9;
ll ub;
map<ll, ll> mp;

ll val(ll x){
	if(x >= ub){
		return 0;
		mp[x] = 0;
	}
	if(mp.find(x) != mp.end()){
		return mp[x];
	}
	// int flag = 0;
	// ll n = x;
	// while(n != 0){
	// 	if(n % 10 != 1){
	// 		flag = 1;
	// 		break;
	// 	}
	// 	n /= 10;
	// }
	// if(flag == 0){
	// 	mp[x] = -1;
	// 	return -1;
	// }
	ll m = x;
	ll minimum = INF;
	while(m != 0){
		ll r = m % 10;
		if(r != 1 && r != 0){
			if(val(x * r) != -1){
				// if(x * r < x){
				// 	minimum = min(minimum , 1ll);
				// }
					minimum = min(minimum, val(x * r) + 1);
				
			}
		}
		m /= 10;
	}
	if(minimum == INF){
		mp[x] = -1;
		return -1;
	}
	mp[x] = minimum;
	return minimum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    ll n, x;
    cin >> n >> x;
    int flag =0;
    ub = pow(10, n - 1);
   	ll ans = val(x);
   	// for(auto x : mp){
   	// 	cout << x.first << " " << x.second << " ";
   	// 	if(x.first >= ub){
   	// 		cout << true;
   	// 	}
   	// 	else{
   	// 		cout << false;
   	// 	}
   	// 	cout << "\n";
   	// }
   	cout << ans << "\n";


}