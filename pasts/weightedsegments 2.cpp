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
	getline(cin, s);

    int n, m;
    cin >> n >> m;

    map<int, int> index;
    vector<pair<int, int>> co(m);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	co[i] = {y, x};
    	index[x] = i + 1;
    }
    sort(co.begin(), co.end());
    ll sum = 0;
    vector<int> final(2 * n, 0);
    for(int i = 0; i < 2 * n; i++){
    	sum += co[i].first;
    	final[i] = co[i].second;
   	}
    sort(final.begin(), final.end());
    cout << sum << "\n";
    for(int i = 0; i < n; i++){
    	cout << index[final[i]] << " " << index[final[2 * n - 1 - i]]<< "\n";
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