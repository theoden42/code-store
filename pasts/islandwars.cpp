
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
    vector<pair<int,int>> p(m);
    for(int i = 0; i < m; i++){
    	int x, y;
    	cin >> x >> y;
    	p[i] = {x, y};
    }
    sort(all(p));
    int sgl = p[0].first;
    int sgr = p[0].second;
    int ans = 1;
    for(int i = 1; i < m; i++){
    	if(p[i].first < sgr){
    		sgl = p[i].first;
    		sgr = min(sgr, p[i].second);
    	}
    	else{
    		ans++;
    		sgl = p[i].first;
    		sgr = p[i].second;
    	}
    }
    cout << ans << "\n";
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