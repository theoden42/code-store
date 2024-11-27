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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<ll> dp(n + 1, 0);
    // dp[0] = 0;
    // dp[min(a, min(b, c))] = 1;
   	// dp[a] = 1;
   	// dp[b] = 1;
   	// dp[c] = 1;

   	for(int i = 0; i <= n; i++){
   		if(dp[i] == 0 && i != 0){
   			continue;
   		}
   		if(a + i <= n){
   			dp[a + i] = max(dp[a + i], dp[i] + 1);
   		}
   		if(b + i <= n){
   			dp[b + i] = max(dp[b + i], dp[i] + 1);
   		}
   		if(c + i <= n){
   			dp[c + i] = max(dp[c + i], dp[i] + 1);
   		}
   	}
   	// for(int i = 0; i <= n; i++){
   	// 	cout << dp[i] << " ";
   	// }
   	// cout << "\n";
   	cout << dp[n] << "\n";
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