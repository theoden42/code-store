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

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> coins(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> coins[i];
    }
    if(n == 1 ){
    	if(x % coins[0] == 0 ){
    		cout << x/coins[0] << "\n";
    	}
    	else{
    		cout << "-1" << "\n";
    	}
    	return;
    }
    vector<int> dp(x + 1, MAX_N);
    for(int i = 0; i < n; i++){
    	dp[coins[i]] = 1;  
    }
    dp[0] = 1;


    for(int i = 0; i <= x; i++){
    	for(int j = 0; j < n; j++){
    		if(i - coins[j] >= 0 && dp[i - coins[j]] != MAX_N){
    			dp[i] = min(dp[i], dp[i - coins[j]] + 1);
    		}
    	}
    }
    if(dp[x] == MAX_N){
    	cout << "-1" << "\n";
    	return;
    }
    cout << dp[x] << '\n';
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