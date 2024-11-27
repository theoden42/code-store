
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
#define int long long

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	vp[i] = {x, y};
    }
    map<int,int> xmap;
    map<int,int> ymap;
    map<pair<int,int>, int> pmap;
    int count = 0;
    for(int i = 0; i < n; i++){
    	int x = vp[i].first;
    	int y = vp[i].second;
    	if(xmap.find(x) == xmap.end()){
    		xmap[x] = 0;
    	}
    	if(ymap.find(y) == ymap.end()){
    		ymap[y] = 0;
    	}
    	if(pmap.find({x, y}) == pmap.end()){
    		pmap[{x, y}] = 0;
    	}
    	int val = xmap[x] + ymap[y] - pmap[{x, y}];
    	debug(xmap, ymap, pmap, i, count);

    	xmap[x]++;
    	ymap[y]++;
    	pmap[{x, y}]++;
    	count += val;
    }
    cout << count << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}