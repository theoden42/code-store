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
    vector<vector<int>> days(n, vector<int> (5, 0));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < 5; j++){
    		cin >> days[i][j];
    	}
    }
    for(int i = 0; i < 5; i++){
    	for(int j = 0; j < 5; j++){
    		if(i == j){
    			continue;
    		}
    		int size1 = 0;
    		int size2 = 0;
    		int size3 = 0;
    		for(int k = 0; k < n; k++){
    			if(days[k][i] == 1 && days[k][j] == 1){
    				size3++;
    			}
    			else if(days[k][i] == 1)
    				size1++;
    			else if(days[k][j] == 1){
    				size2++;
    			}
    		}
    		if(size1 == n/2 && size2 == n/2){
    			cout << "YES" << "\n";

    			return;
    		}
    		else if(size1 + size2 + size3 == n && size3 >= n/2 - min(size1, size2) && max(size1, size2) + (size3 - n/2 + min(size1, size2)) == n/2){
    			cout << "YES" << "\n";
    			return;
    		}
    	}
    }
    cout << "NO" << "\n";
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