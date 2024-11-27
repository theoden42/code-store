

	/* author: (g)theoden42 */

	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>

	using namespace std;
	using namespace __gnu_pbds;

	#define all(a) a.begin(), a.end()
	#ifdef ON_PC
	    #include <debug.h>
	#else
	    #define debug(x...)
	#endif

	template<typename T>
	using ordset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
	using ll =  long long;
	using ld = long double;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	const int MAX_N = 1e6 + 5;
	const ll MOD = 1e9 + 7;
	const ll INF = 1e9;
	#define int long long

	void solve() {
	    string s;
	    cin >> s;
	    int n = s.size();


	    int val = 1e12;	
	    int ans = 0;


	    int c0 = 0;
	    for(int i = 0; i < n; i++){
	    	c0 += (s[i] == '0');
	    }

	    int mn = c0 * (val + 1);

	   	for(int i = 0; i < n; i++){
	   		if(s[i] == '0'){
	   			c0--;
	   		}
	   		else{
	   			int j = i;
	   			int count = 0;
	   			while(j < n && s[j] == '1'){
	   				count++;
	   				j++;
	   			}

	   			if(j == n)break;
   				int temp = ans + c0 * (val + 1);

   				if(count == 1 && (j == n - 1 || (j < n - 1 && s[j + 1] == '1'))){
   					temp = ans + (c0 - 1) * (val + 1) + val;
   				}
   				mn = min(mn, temp);
   				ans += (count) * (val + 1);	
   				i = j - 1;
   			}
	   	}

	   	mn = min(mn, ans);
	   	cout << mn << "\n";

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