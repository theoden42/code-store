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
    string s, t;
    cin >> s >> t;
    int m = t.length();
    int n = s.length();
    string str = "";
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));

    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		if(s[i - 1] == t[j - 1]){
    			dp[i][j] = dp[i - 1][j - 1] + 1;
    		}
    		else {
    			if(dp[i - 1][j] >= dp[i][j - 1]){
    				dp[i][j] = dp[i - 1][j];
    			}
    			else{
    				dp[i][j] = dp[i][j - 1];
    			}
    		}
    	}
    }
    char lcs[dp[n][m]];
    int index = dp[n][m];
    lcs[index + 1] = '\0';
    int i = n, j = m;
    while(i > 0 && j > 0){
    	if(s[i - 1] == t[j - 1]){
    		lcs[index] = s[i - 1];
    		i--;
    		j--;
    		index--;
     	}
     	else if(dp[i - 1][j] > dp[i][j - 1]){
     		i--;
     	}
     	else{
     		j--;
     	}
    }
    for(int i = 1; i <= dp[n][m]; i++){
    	cout << lcs[i];
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}