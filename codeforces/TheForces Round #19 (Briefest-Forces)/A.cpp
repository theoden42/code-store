

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
	    int l1, r1, l2, r2;
	    cin >> l1 >> r1 >> l2 >> r2;


	    int len1 = (r1 - l1 + 1);
	    int len2 = (r2 - l2 + 1);

	    int s1 = (r1 * (r1 + 1)) / 2 - (l1 * (l1 - 1)) / 2;
	    int s2 = (r2 * (r2 + 1)) / 2 - (l2 * (l2 - 1)) / 2;

	    double e1 = (1.0 * s1) / len1;
	    double e2 = (1.0 * s2) / len2;

	 
	   if(e1 > e2){
	   	  cout << "YES\n";
	   }
	   else{
	   	  cout << "NO\n";
	   }


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