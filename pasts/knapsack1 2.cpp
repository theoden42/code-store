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



void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> weight(n);
    ll sum = 0;
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	weight[i] = {x, y};
    	sum += x;
    }

    vector<vector<ll>> dp(n + 1, vector<ll> (w + 1, 0));
  	for(int i = 1; i <= n; i++){
  		for(int x = 1; x <= min(sum, (long long)w); x++){
  			if(x < weight[i-1].first){
  				dp[i][x] = dp[i-1][x];
  				continue;
  			}
  			dp[i][x] = max(dp[i-1][x], dp[i-1][x - weight[i-1].first] + weight[i-1].second);
  		}
  	}
    ll ans = 0;
    for(auto& x : dp){
    	for(ll val : x ){
    		ans = max(ans, val);
    	}
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}