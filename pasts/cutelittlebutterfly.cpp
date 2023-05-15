
/* @uthor: (g)theoden42 */

#include <bits/stdc++.h>
using namespace std;

#ifdef ON_PC
    #include <debug.h>
#else
    #define debug(x...)
#endif

#define ll long long
#define ld long double
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

ll maxenergy(vector<int>& x, vector<int>& y, vector<int>& c, vector<int>& vis, ll xb, ll yb, ll d, ll e){
	debug(xb, yb);
	int n = x.size();
	ll mx = 0;
    for(int i = 0; i < n; i++){
    	if(!vis[i] && y[i] <= yb){
    		vis[i] = 1;
    		if(d * (x[i] - xb) > 0){
    			mx = max(mx, c[i] + maxenergy(x, y, c, vis, x[i], y[i], d, e));		
    		}
    		else{
    			mx = max(mx, c[i] + maxenergy(x, y, c, vis, x[i], y[i], -1 * d, e) + e);	
    		}
    		vis[i] = 0;
    	}
    }	
    return mx;
}
	

void solve() {
    int n, e;
    cin >> n >> e;
    vector<int> x(n, 0);
    vector<int> y(n, 0);
    vector<int> c(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> x[i] >> y[i] >> c[i];n
    }
    vector<pair<pair<int,int>,int>> vpp(n);
    for(int i = 0; i < n; i++){
    	vpp[i] = {{x[i], y[i]}, c[i]};
    }
    vector<int> vis(n, 0);
    cout << maxenergy(x, y, c, vis, 0, 1e18, 1, e) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}