
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
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    for(int i = 0; i < n; i++){
    	cin >> a[i];
    }
    for(int i = 0; i < n; i++){
    	cin >> b[i];
    }

    ll l = 0;
    ll u = 2e9;
    ll mx = 0;

    while(l <= u){
    	ll mid = l + (u - l) / 2;
    	debug(l, mid, u);
    	ll x = k;	
    	int f = 0;
    	for(int i = 0; i < n; i++){
    		debug(b[i], mid, a[i], x);

    		if(b[i] >= a[i] * mid){
    			continue;
    		}
    		else if(x >= (a[i] * mid - b[i])){
    			x -= (a[i] * mid - b[i]);
    			debug("here");
    		}
    		else{
    			f = 1;
    			break;
    		}
    	}
    	if(!f){
    		mx = max(mx, mid);
    		l = mid + 1;
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