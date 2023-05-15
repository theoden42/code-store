
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
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	vp[i] = {a, b};
    }

    sort(all(vp));
    vector<int> vis(n, 0);
    int count = 0;
    int subsegment = 0;
    vector<int> points;
    


    for(int i = 0; i < n; i++){
    	for(int j = i + 1; j < n; j++){

    		double slope = 10000;
    		if(vp[j].first != vp[i].first){
    			slope = abs((vp[j].second - vp[i].second) / (1.0 * vp[j].first - vp[i].first));
    		}
    		int count = 2;
	
    		for(int k = j + 1; k < n; k++){
    			double temp = 10000;
    			if(vp[j].first != vp[k].first){
    				 temp = abs((vp[j].second - vp[k].second) / (1.0 * vp[j].first - vp[k].first));
    			}
    			if(temp == slope){

    			}
    		}
    		points.push_back(count);
    	}
    }


    ll ans = (n * (n - 1) * (n - 2)) / 6;
    for(auto& x: points){
    	if(x < 3)continue;
    	ans -= ((x - 1) * x * (x - 2)) / 6;
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