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
    string s, t;
    cin >> s >> t;
	int n = s.length();
	int m = t.length();
	vector<int> ind;
	int j = m - 1;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == t[j]){
			ind.push_back(i);
			j--;
		}
	}
	if(ind.size() < m){
		cout << "NO" << "\n";
	}
	else{
		for(int i = ind[0] + 1; i < n; i++){
			for(int k = 0; k < m; k++){
				if(t[k] == s[i]){
					cout << "NO" <<"\n";
					return;
				}
			}
		}
		map<int,int> freq;
		for(auto& x : ind){
			freq[x] = 1;
		}
		for(int i = ind[ind.size() - 1]; i <= ind[0]; i++){
			if(freq.find(i) == freq.end()){
					continue;
			}
			for(int j = i + 1; j <= ind[0]; j++){
				if(s[i] == s[j] && freq.find(j) == freq.end()){
					cout << "NO" << "\n";
					return;
				}
			}
		}
		cout << "YES" << "\n";
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