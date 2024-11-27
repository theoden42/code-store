
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s;
    cin >> t;
    vector<int> mx(m, 0);
    vector<int> mn(m, 0);
    int x = n - 1;
    for(int i = m - 1; i >= 0; i--){
    	while(s[x] != t[i])x--;
    	mx[i] = x;
    	x--;
    }
	x = 0;
    for(int i = 0; i < m; i++){
    	while(s[x] != t[i])x++;
    	mn[i] = x;
    	x++;
    }

    // for(int i = 0; i <= m - 1; i++){
    // 	cout << mx[i] << " " << mn[i] << "\n";
    // }
    int maxx = 0;
    for(int i = 0; i < m - 1; i++){
    	maxx = max(maxx, mx[i + 1] - mn[i]);
    }
    cout << maxx << "\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}