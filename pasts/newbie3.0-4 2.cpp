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
    int n, m;
    cin >> n >> m;
   	vector<vector<char>> s(n, vector<char> (m, 'a'));
   	for(int i = 0; i < n; i++){
   		string str;
   		cin >> str;
   		for(int j = 0; j < m; j++){
   			s[i][j] = str[j];
   		}
   	}
   	ll val = 0;
   	ll count = 0;
   	for(int j = 0; j < m; j++){
   		val = 0;
   		for(int i = 0; i < n; i++){
   			if(s[i][j] == 'v'){
   				val++;
   			}
   			else if(s[i][j] == '^'){
   				count += val;
   			}
   			else{
   				val = 0;
   			}
   		}
   	}
   	for(int i = 0; i < n; i++){
   		val = 0;
   		for(int j = 0; j < m; j++){
   			if(s[i][j] == '>'){
   				val++;
   			}
   			else if(s[i][j] == '<'){
   				count += val;
   			}
   			else{
   				val = 0;
   			}
   		}
   	}
   	cout << count << "\n";
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