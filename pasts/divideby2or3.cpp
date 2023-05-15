
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
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }
    vector<pair<int,int>> vp(n);
    int val = -1;

    for(int i = 0; i < n; i++){
    	int x = ele[i];
    	int c = 0;
    	while(x % 2 == 0){
    		x /= 2;
    		c++;
    	}
    	int c2 = 0;
    	while(x % 3 == 0){
    		x /= 3;
    		c2++;
    	}
    	if(val == -1){
    		val = x;
    		vp[i] = {c, c2};
    	}
    	else if(val != x){
    		cout << "-1\n";
    		return;
    	}
    	else{
    		vp[i] = {c, c2};
    	}
    }
    int mx1 = vp[0].first;
    int mx2 = vp[0].second;
    for(int i = 0; i < n; ++i){
    	mx1 = min(mx1, vp[i].first);
    	mx2 = min(mx2, vp[i].second);
    }
	ll sum = 0;
	for(int i = 0; i < n; ++i){
		sum += vp[i].first - mx1;
		sum += vp[i].second - mx2;
	}
	cout << sum << "\n";

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