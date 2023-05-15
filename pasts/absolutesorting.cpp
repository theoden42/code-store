
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
#define int long long 
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;


void solve() {
    int n;
    cin >> n;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }


    int l = 0, r = 1e9;


    for(int i = 1; i < n; i++){
    	debug(l, r, i);
    	if(ele[i] == ele[i - 1])continue;

    	if(ele[i] > ele[i - 1]){
    		int avg = (ele[i] + ele[i - 1]) / 2;
    		r = min(r, avg);
     	}
     	else{
     		int avg = (ele[i] + ele[i - 1] + 1) / 2;
     		l = max(l, avg);
     	}

    }

    // for(int i = 0; i < n; i++){
    // 	cout << abs(ele[i] - r) << " ";
    // }
    // cout << "\n";

    debug(l, r);
    if(l <= r){
    	cout << r << "\n";
    }
    else{
    	cout << "-1\n";
    }

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