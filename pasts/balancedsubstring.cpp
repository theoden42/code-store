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
	string s;
	cin >> s;
	vector<int> ele(n, 0);
	if(s[0] == 'a'){
		ele[0] = 1;
	}
	for(int i = 1; i < n; i++){
		if(s[i] == 'a'){
			ele[i] = ele[i - 1] + 1;
		}
		else{
			ele[i] = ele[i - 1];
		}
	}
	for(int j = 0; j < n; j++){
		for(int k = j + 1; k < n; k++){
			int y = 0;
			if(s[j] == 'a'){
				y = 2 * (ele[k] - ele[j] + 1);
			}
			else{
				y = 2 * (ele[k] - ele[j]);
			}
			if((k - j + 1) == y){
				cout << j + 1 << " " << k + 1<< "\n";
				return;
			}
		}
	}
	cout << "-1 -1" << "\n";
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