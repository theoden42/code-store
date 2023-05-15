
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
	    ll k, n;
	    cin >> k >> n;
	    debug(k, n);
	    vector<ll> ele(n, 0);

	    for(int i = 0; i < n; i++){
	    	cin >> ele[i];
	    }

	    debug(ele);

	    auto check = [&](ll g){
	    	ll sum = 0;
	    	for(int i = 0; i < n; i++){
	    		sum += min(ele[i], g);
	    	}	
	    	if(sum >= g * k)
	    		return 1;
	    	else 
	    		return 0;
	    };


	   	ll l = 0;
	   	ll u = 1e12;
	   	ll mx = 0;


	   	while(l <= u){
	   		ll mid = l + (u - l) / 2;
	   		if(check(mid)){
	   			l = mid + 1;
	   			mx = max(mx, mid);
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