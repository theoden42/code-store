
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
    string s;
    cin >> s;
    map<char,int> mp;
    for(int i = 0; i < n; i++){
    	mp[s[i]] += 1;
    }
    int l = 1;
    int u = n;
    int ans = 1;

    debug(mp);
    auto check = [&](int val){

    	if(!(val & 1)){
    		int req = (k * val) / 2;
    		for(auto& x: mp){
    			req -= x.second / 2;
    		}
    		debug(val);
    		if(req <= 0)return true;
    		else return false;
    	}
    	else{
    		int req1 = k * (val / 2);
    		int req2 = k;
    		debug(req1, req2);
  			for(auto& x: mp){
  				int v = x.second;
  				int l = min(req1, v / 2);
  				v -= 2 * l;
  				req1 -= l;


  				if(req1 == 0){
  					req2 -= min(req2, v);
  				}
  				else{
  					req2 -= min(req2, v % 2);
  				}
  			}
  			if(req1 == 0 && req2 == 0)return true;
  			else return false;
    	}
    };

    while(l <= u){
    	int mid = l + (u - l) / 2;
    	debug(mid);
    	if(check(mid)){
    		ans = mid;
    		l = mid + 1;
    	}
    	else{
    		u = mid - 1;
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