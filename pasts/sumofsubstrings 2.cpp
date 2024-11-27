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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ind1 = -1;
    int ind2 = -1 ;
    int count = 0;
    for(int i = 0; i < n; i++){
    	if(s[i] == '1'){
    		count++;
    	}
    }
    for(int i = n - 1; i >= 0; i--){
    	if(s[i] == '1'){
    		ind1 = i;
    		break;
    	}
    }
    for(int i = 0; i < n; i++){
    	if(s[i] == '1'){
    		ind2 = i;
    		break;
    	}
    }
    if(ind1 < n - 1 && ind1 != -1){
    	if(k >= n - 1 - ind1){
    		k -= (n - 1) - ind1;
    		s[ind1] = '0';
    		s[n - 1] = '1';
    		if(count == 1){
    			ind2 = n - 1;
    		}
    	}
    }
    if(ind2 > 0 && ind2 != n - 1){
    	if(k >= ind2){
    		s[ind2] = '0';
    		s[0] = '1';
    	}
    }
    ll sum = 0;
    for(int i = 0; i < n - 1; i++){
    	if(s[i] == '0'){
    		if(s[i + 1] == '1'){
    			sum += 1;
    		}
    	}
    	else{
    		if(s[i + 1] == '1'){
    			sum += 11;
    		}
    		else{
    			sum += 10;
    		}
    	}
    }
    cout << sum << "\n";
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