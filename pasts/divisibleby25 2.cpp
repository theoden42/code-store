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
    int n = s.length();
    int index1 = -1;
    int index2 = -1;
    int m = MAX_N;
    for(int i = n - 1; i >= 0; i--){
    	if(s[i] == '0'){
    		index1 = i;
    		break;
    	}
    }
    for(int i = n - 1; i >= 0; i--){
    	if(s[i] == '5'){
    		index2 = i;
    		break;
    	}
    }
    for(int i = n - 1; i >= 0; i--){
    	if(s[i] == '2' || s[i] == '7'){
    		if(index2 != -1 && i < index2){
    			m = min(m, n - 2 - i );
    			break;
    		}
    	}
    }
     for(int i = n - 1; i >= 0; i--){
    	if(s[i] == '0' || s[i] == '5'){
    		if(index1 != -1 && i < index1){
    			m = min(m, n - 2 - i);
    			break;
    		}
    	}
    }
	cout << m << "\n";
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