
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
    int n, k;
    cin >> n >> k;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }


    vector<pair<int,int>> vp(n);
    for(int i = 0; i < n; i++){
    	vp[i] = {ele[i] - n + 1 + i, i};
    }

    debug(vp);
    sort(all(vp));



    int temp = k;
    for(int i = n - 1; i >= 0; i--){
    	int x = vp[i].second;
    	if(temp > 0){
    		ele[x] = -1;
    		temp--;
    	}
    }

    int ans = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
    	if(ele[i] == -1){
    		count++;
    	}
    	else{
    		ans += count + ele[i];
    	}
    }
    cout << ans << "\n";
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