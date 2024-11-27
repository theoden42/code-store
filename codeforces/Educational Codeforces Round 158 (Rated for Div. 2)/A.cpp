

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
	    int n, x;
	    cin >> n >> x;
	    vector<int> a(n);
	    map<int,int> mp;
	    for(int i = 0; i < n; i++){
	    	cin >> a[i];
	    	mp[a[i]] = 1;
	    }
	    for(int j = 1; j <= 2 * (x + 1); j++){
	    	int curr = j;
	    	int point = 0;
	    	while(point < x && curr > 0){
	    		point += 1;
	    		curr -= 1;
	    		if(mp[point]){
	    			curr = j;
	    		}	
	    	}
	    	if(point != x){
	    		continue;
	    	}
	    	while(point > 0 && curr > 0){
	    		point -= 1;
	    		curr -= 1;
	    		if(mp[point]){
	    			curr = j;
	    		}
	    	}
	    	if(point == 0){
	    		cout << j << "\n";
	    		return;
	    	}
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