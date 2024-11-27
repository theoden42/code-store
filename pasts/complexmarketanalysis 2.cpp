
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




bool isprime(int val){
	for(int i = 2; i * i <= val; i++){
		if(val % i == 0){
			return 0;
		}
	}
	return 1;
}

void solve() {
    int e, n;
    cin >> n >> e;
    vector<int> ele(n);
    for(int i = 0; i < n; i++){
    	cin >> ele[i];
    }

    ll ans = 0;
    for(int i = 0; i < e; i++){
    	debug(i);

    	int j = i;

    	ll count = 0;
    	int lstcount = 0;
    	int f = 0;

    	while(j < n){
    		debug(i, ele[j], e, isprime(ele[j]));

	    	if(ele[j] == 1){
	    		count++;
	    		j += e;
	    		continue;
	    	}
	    	if(isprime(ele[j])){

	    		if(f){
	    			ans += (count) * lstcount + 2 * count;
	    		}
	    		else{
	    			ans += count;
	    		}
	    		lstcount = count;
	    		f = 1;
	    		count = 0;
	    	}
	    	else{
	    		if(f){
	    			ans += (count) * lstcount + count;
	    		}
	    		lstcount = 0;
	    		f = 0;
	    		count = 0;
	    	}
	    	j += e;
    	}
    	if(f){
    		ans += count * lstcount + count;
    	}

    	debug(ans);
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