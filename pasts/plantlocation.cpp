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

ld y(int a, int b, int c, ld x){
	ld ans = -1 * 1ll * (c + a * x)/(long double)b;
	return ans;
}
ld sum (vector<pair<int, int>> war, ld x, ld y, int a, int b){
	ld s = 0;
	for(auto& w : war){
		ld xi = w.first;
		ld yi = w.second;
		s += (((x - xi) - ((y - yi) * a)/(long double)b))/(long double)(sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi)));
	}
	return s;
}
ld fd(vector<pair<int,int>> war, ll x, ll y){
	ld s = 0;
	for(auto& w : war){
		ld xi = w.first;
		ld yi = w.second;
		s += sqrt((x - xi) * (x - xi) + (y - yi) * (y - yi));
	}
	return s;
}

void solve() {
    int n;
    int a , b , c;
    cin >> n >> a >> b >> c;
    vector<pair<int, int>> war;
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	war.emplace_back(x, y);
    }
    ld left = -5000;
    ld right = 5000;
	ld ans = 0;

    while(left < right){
    	ld mid = left + (right - left)/2.0;
    	// cout << mid << ": \n";
    	// cout << " " << y(a,b,c, mid)<<  "\n";
    	ld val = sum(war, mid, y(a, b, c, mid), a, b);
    	 cout << val << ": " << "\n";
    	if(abs(val) < 1e-15){
    		ans = val;
    		break;
    	}
    	else{
    		if(val < 0){
    			left = mid + 1e-15;
    		}
    		else{
    			right = mid - 1e-15;
    		}
    	}
    }
    ld dist = fd(war, ans, y(a, b, c, ans));
    printf("%.6lf \n", dist);
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