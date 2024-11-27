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

const int MAX_N = 2e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;  
vector<vector<int>> bits(MAX_N, vector<int> (32, 0));


void solve() {
    int l, r;
    cin >> l >> r;
    vector<int> bit(32, 0);
    int n = r - l + 1;
    int ans = 0;
    int min = r - l;
    for(int i = 0; i < 32; i++){
    	ans = n - (bits[r][i] - bits[l-1][i]);
    	if(ans <= min){
    		min = ans;
    	}
    }
    cout << min << " \n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;


    for(int i = 1; i < MAX_N; i++){
    	int x = i;
    	int j = 0;
    	while(x != 0){
    		if( (x & 1) == 1){
    			bits[i][j] = bits[i-1][j] + 1;;
    		}
    		else{
    			bits[i][j] = bits[i-1][j];
    		}
    		j++;
    		x = x >> 1;
    	}
    }



    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}