
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
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> c(n, {0,0});
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	c[i] = {x, y};
    }
    ld l = 0.0;
    for(int i = 1; i < n; i++){
    	int a = c[i].first - c[i - 1].first;
    	int b = c[i].second - c[i - 1].second;
    	l += sqrt(a * a + b * b);
    }
    l = l * k;
    ld time = l / 50;
   	cout << setprecision(10) << time << "\n";
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