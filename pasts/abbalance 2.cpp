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
    int c1 = 0;
    int c2 = 0;
    int n = s.length();
    for(int i = 0; i < n - 1; i++){
    	if(s[i] == 'a' && s[i + 1] == 'b'){
    		c1++;
    	}
    	else if(s[i] == 'b' && s[i + 1] == 'b'){
    		c2++;
    	}
    }
    string ans = "";
    if(c1 == c2){
    	cout << s << "\n";
    	return;
    }
    else if(c1 < c2){
    	if(s[n - 1] == 'a'){
    		
    	}
    }
    else{
    	int val = c1 - c2;
    	for(int i = 0; i < n - 1; i++){
    		if(s[i] == 'b' && s[i + 1] != 'a' && val > 0){
    			ans += "ba";
    			val--;
    		}
    		else{
    			ans += s[i];
    		}
    	}
    	for(int j = 1; j <= val; j++){
    		ans += "ba";
    	}
    }
    cout << ans << "\n";
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