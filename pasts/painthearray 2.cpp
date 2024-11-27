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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<int> one;
    vector<int> two;
    for(int i = 0; i < n; i += 2){
    	one.push_back(ele[i]);
    }
    for(int i = 1; i < n; i += 2){
    	two.push_back(ele[i]);
    }
    int gcda = one.back();
    for(auto& x : one){
    	gcda = __gcd(gcda, x);
    }
    for(int i = 1; i * i <= gcda; i++){
    	int flag = 1;
    	if(gcda % i == 0){
    		for(auto& y: two){
    			if(y % i == 0){
    				flag = 0;
    				break;
    			}
    		}
    		if(flag == 1){
    			cout << i << "\n";
    			return;
    		}
    	}
    }

    ll gcdb = one.back();
    for(auto& x : one){
    	gcda = __gcd(gcda, x);
    }
    for(ll i = 1; i * i <= gcda; i++){
    	int flag = 1;
    	if(gcda % i == 0){
    		for(auto& y: two){
    			if(y % i == 0){
    				flag = 0;
    				break;
    			}
    		}
    		if(flag == 1){
    			cout << i << "\n";
    			return;
    		}
    	}
    }
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