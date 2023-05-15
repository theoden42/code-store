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
     int n;
     cin >> n;
     vector<int> r(n, 0);
     int m;
     for(int i = 0; i < n; i++){
     	cin >> r[i];
     }
     cin >> m;
     vector<int> b(m, 0);
     for(int i = 0; i < m; i++){
     	cin >> b[i];
     }
     // for(int i = 0; i < n; i++){
     // 	cout << r[i] << " ";
     // }
     // cout << "\n";
     // for(int j = 0; j < m; j++){
     // 	cout << b[j] << " ";
     // }
     // cout << "\n";
     vector<vector<ll>> dp(n + 1, vector<ll> (m + 1 , 0));
     for(int i = 1; i <= n; i++){
     	dp[i][0] = dp[i - 1][0] + r[i - 1];
     }
     for(int j = 1; j <= m; j++){
     	dp[0][j] = dp[0][j - 1] + b[j - 1];
     }
     for(int i = 1; i <= n; i++){
     	for(int j = 1; j <= m; j++){

     		dp[i][j] = dp[i][j - 1] + b[j - 1];
     		dp[i][j] = max(dp[i][j], dp[i - 1][j] + r[i - 1]);
     	}
     }
     ll ma = 0;
     for(int i = 0; i <= n; i++){
     	for(int j = 0; j <= m; j++){
     		// cout << dp[i][j] << " ";
     		ma = max(ma, dp[i][j]);
     	}
     	// cout << "\n";
     }
     cout << ma << "\n";
 }
 
 int main() {
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);
     int tc = 1;
     cin >> tc;
     for (int t = 1; t <= tc; t++) {
         // cout << "Case #" << t << ": ";
         solve();
     }
 }