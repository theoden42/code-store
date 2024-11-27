
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
    int n, k;
    cin >> n >> k;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    if(n > 3000){
    	int m = -1e9;
    	for(int i = n - 1; i >= n - 2000; i--){
    		for(int j = n - 1; j >= n - 2000; j--){
				if(i == j)continue;

				ll val = (i + 1) * (j + 1) - k * (ele[i] | ele[j]);
    			m = max(m, val);
    		}
       	}
       	cout << m << "\n";
       	return;
    }

    int mx = -1e9;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		if(i == j)continue;

    		ll val = (i + 1) * (j + 1) - k * (ele[i] | ele[j]);
    		mx = max(val, mx);
    	}
    }


    cout << mx << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}