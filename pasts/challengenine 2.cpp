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
 	string s;
 	cin >> s;
    long long sum = 0;
  	for(int i = 0; i < s.length(); i++){
  		sum += (s[i] - '0');
  	}
    int count = (9 - (sum % 9));
    if(count == 9){
    	count = 0;
    }
    string ans = "";
   	if(count == 0){
   		ans = s.substr(0, 1) + "0" + s.substr(1, s.length());
   		cout << ans << '\n';
   		return;
   	}
    int i = 0;
    for(i = 0; i < s.length(); i++){
    	if((s[i] - '0') > count){
    		ans = ans + (char)('0' + count) + s.substr(i, s.length());
    		break;
    	}
    	else{
    		ans += s[i];
    	}
    }
    if(i == s.length()){
    	ans =  ans + (char)('0' + count);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}