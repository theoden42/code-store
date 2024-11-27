
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
    int n, k;
    cin >> n >> k;
    vector<int> ele(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    auto check = [&](ll val){
		int curr = ele[0];
		int count = 1;
		for(int i = 1; i < n; i++){
			if(ele[i] >= curr + val){
				curr = ele[i];
				count++;
			}
			else{
				continue;
			}
		}
		if(count >= k){
			return true;
		}
		else{
			return false;	
		}
    };

    ll l = 0;
    ll u = 1e9;
    ll mx = 0;
    for(int i = 0; i < 50; i++){
    	ll mid = l + (u - l) / 2;
    	if(check(mid)){
    		l = mid + 1;
    		mx = mid;
    	}
    	else{
    		u = mid - 1;
    	}
    }
    cout << mx << "\n";
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