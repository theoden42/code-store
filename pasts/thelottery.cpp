
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

	int gcd(int a, int b){
		return a == 0 ? b : gcd(b % a, a);
	}

	void solve() {
	    int n;
	    while(cin >> n){
	    	int m;
	    	cin >> m;
	    	debug(m);
	    	vector<int> ele(m);
	    	for(int i = 0; i < m; ++i){
	    		cin >> ele[i];
	    	}
	    	int count = 0;
	    	for(int i = 0; i < m; i++){
	    		if(ele[i] == 0)continue;
	    		count += n / ele[i];
	    	}
	    	for(int i = 0; i < m; i++){
	    		for(int j = i + 1; j < m; j++){
	    			if(ele[i] == 0 || ele[j] == 0)continue;
	    			int g = (ele[i] * ele[j]) / gcd(ele[i], ele[j]);
	    			count -= n / g;
	    		}
	    	}
	    	debug(count, n);
	    	cout << n - count << "\n";
	    }
	}

	int32_t main() {
	    ios_base::sync_with_stdio(0);
	    cin.tie(0); cout.tie(0);
	    int tc = 1;
	    //cin >> tc;
	    for (int t = 1; t <= tc; t++) {
	        // cout << "Case #" << t << ": ";
	        solve();
	    }
	}