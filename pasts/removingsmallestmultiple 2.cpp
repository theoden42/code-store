
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
		  int n;
		  cin >> n;
		  string s;
		  cin >> s;
		  vector<ll> dels;

		  for(int i = 0; i < n; i++){
		  	if(s[i] == '0'){
		  		dels.push_back(i + 1);
		  	}
		  }

		  ll sum = 0;

		  debug(dels);

		  vector<ll> deletecost(n + 1, 0);
		  for(int i = 1; i <= n; i++){
		  	deletecost[i] = i;
		  }
	 
		  for(int i = 0; i < (int)dels.size(); i++){
		  	ll x = dels[i];
		  	for(int j = 1; j <= n / x; j++){
		  		if(s[x * j - 1] == '1'){
		  			break;
		  		}
		  		deletecost[x * j] = min(deletecost[x * j], x);
		  	}
		  }
		  for(int i = 0; i < n; i++){
		  	if(s[i] == '0')
		  	sum += deletecost[i + 1];
		  }

		  cout << sum << "\n";
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