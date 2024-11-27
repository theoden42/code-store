
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

	int __gcd(int a, int b)
	{
	    if (a == 0)
	        return b;
	    return __gcd(b % a, a);
	}
	void solve() {
	    int n;
	    cin >> n;
	    vector<int> ele(n, 0);
	    for(int i = 0; i < n; i++){
	    	cin >> ele[i];
	    }
	    vector<int> b(n + 1, 0);
	    b[0] = ele[0];
	    b[1] = ele[0];
	    int r = ele[0];
	  	for(int i = 1; i < n; i++){
	  		if(b[i] % ele[i] == 0){
	  			b[i + 1] = ele[i];
	  		}
	  		else{
	  			int x = (b[i] * ele[i]) / __gcd(b[i], ele[i]);
	  			b[i] = x;
	  			b[i + 1] = ele[i];
	  		}
	  	}
	  	debug(b);
	  	for(int i = 0; i < n; i++){
	  		debug(b[i], b[i + 1], __gcd(b[i + 1], b[i]));
	  		if(__gcd(b[i], b[i + 1]) == ele[i]){
	  			continue;
	  		}
	  		else{
	  			debug(b[i], b[i + 1], ele[i]);
	  			cout << "NO" << "\n";
	  			return;
	  		}
	  	}
	  	cout << "YES" << "\n";
	}

	int main() {
	    ios_base::sync_with_stdio(0);
	    cin.tie(0); cout.tie(0);
	    int tc = 1;
	    cin >> tc;
	    for (int t = 1; t <= tc; t++) {
	        // cout << "Case #" << t << ": ";
	        solve();
	    }
	}