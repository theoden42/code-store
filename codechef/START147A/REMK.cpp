

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
	    int n, k;
	    cin >> n >> k;
	    vector<int> a(n);
	    for(int i = 0; i < n; i++){
	    	cin >> a[i];
	    }
	    vector<vector<int>> count(n + 1, vector<int>(61, 0)), farthest(n + 1, vector<int>(61, -1));

	    for(int i = 1; i <= n; i++){
	    	for(int j = 0; j < 60; j++){
	    		count[i][j] += count[i - 1][j];
	    	}
	    	count[i][a[i - 1]] += 1;
	    }
	    for(int j = n; j > 0; j--){
	    	int x = a[j - 1];
	    	for(int k = 0; k < 60 && j != n; k++){
	    		farthest[j][k] = farthest[j + 1][k];
	    	}
	    	if(farthest[j][x] == -1){
	    		farthest[j][x] = j;
	    	}
	    }
	    int mx = 0;
	    for(int i = 1; i < n; i++){
	    	for(int j = 1; j < 60; j++){
	    		int sum = 0;
	    		sum += a[i - 1] + j;
	    		int x = farthest[i + 1][j];
	    		if(x == -1)
	    			continue;
	    		vector<int> temp(60);
	    		for(int k = 1; k < 60; k++){
	    			temp[k] = count[x - 1][k] - count[i][k];
	    		}
	    		int rem = k - 2;
	    		int ind = 59;
	    		while(rem > 0 && ind >= 1){
					int t = min(temp[ind], rem);
					rem -= t;
					sum += 2 * t * ind;
					ind -= 1;
	    		}
	    		if(rem == 0){
	    			mx = max(mx, sum);
	    		}
	    	}
	    }
	    cout << mx << "\n";
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