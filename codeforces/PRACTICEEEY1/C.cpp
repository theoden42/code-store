

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

	void solve() {
	    int n;
	    cin >> n;
	    vector<int> dp(11);
	    dp[1] = 1;
	    for(int i = 2; i <= 11; i++){
	    	int f = 1;	
	    	for(int j = 2; j * j <= i; j++){
	    		if(i % j == 0){
	    			int f1 = j;
	    			int f2 = i / j;
	    			if(dp[i - f1] == 1 || dp[i - f2] == 1){
	    				f = 0;
	    				break;
	    			}
	    		}
	    	}
	    	dp[i] = f;
	    }
	    if(n <= 10){
	    	if(dp[n] & 1){
	    		cout << "Bob\n";
	    	}
	    	else {
	    		cout << "Alice\n";
	    	}
	    	return;
	    }
	    int count = 0;
	    int temp = n;
	    while(n % 2 == 0){
	    	count++;
	    	n /= 2;
	    }
	    if(n == 1){
	    	if(count & 1){
	    		cout << "Bob\n";
	    	} else {
	    		cout << "Alice\n";
	    	}
	    	return;
	    }
	    if(temp & 1){
	    	cout << "Bob\n";
	    } else {
	    	cout << "Alice\n";
	    }

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