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
    vector<vector<ll>> grid(n + 1, vector<ll>(n + 1, 0));
    for(int i = 1; i <= n; i++){
    	string s;
    	cin >> s;
    	for(int j = 1; j <= n; j++){
    		if(s[j - 1] == '*'){
    			grid[i][j] = -1;
    		}
    	}
    }
 	if(grid[1][1] == -1){
 		cout << "0" << "\n";
 		return;
 	}
    vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 0));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= n; j++){
    		if(i == 1 && j == 1){
    			continue;
    		}
    		if(grid[i][j] == -1){
    			dp[i][j] = 0;
    		}
    		else{
    			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
    		}
    	}
    }
    if(dp[n][n] == -1){
    	cout << "0" << '\n';
    	return;
    }

    cout << dp[n][n] << "\n";
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