
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

void solve() {
    ll s, n;
    cin >> s >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		vp[i] = {x, y};
    }
    sort(all(vp));
    for(int i = 0; i < n; i++){
    	if(s <= vp[i].first){
    		cout << "NO" << "\n";
    		return;
    	}
    	else{
    		s += vp[i].second;
    	}
    }
    cout << "YES" << "\n";
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