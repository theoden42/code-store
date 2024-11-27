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
const ll INF = 1e9 + 10;
const ld EPS = 1e-9;



void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> items(n);
    ll sum = 0;
    ll sum2 = 0;
    for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		items[i] = {x, y};
		sum += y;
		sum2 += x;

    }
    vector<vector<long long>> dp(n, vector<long long>(sum + 1, sum2));
    for(int i = sum; i >= 0; i--){
    	if(i <= items[n - 1].second){
    		dp[n-1][i] = items[n - 1].first;
    	}
    }
    for(int i = n - 2; i >= 0; i--){
    	for(int j = sum; j >= 0; j--){
    		if(j < items[i].second){
    			dp[i][j] = dp[i + 1][j];
    			continue;
    		}
    		dp[i][j] = min(dp[i+1][j], dp[i+1][j - items[i].second] + items[i].first);
    	}
    }
    for(int i = sum; i >= 0; i--){
    	for(int j = n - 1; j >= 0; j--){
    		if(dp[j][i] <= w){
    			cout << i << '\n';
    			return;
    		}
    	}
    }
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