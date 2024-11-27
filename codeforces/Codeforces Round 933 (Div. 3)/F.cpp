

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
	    int n, m, k;
	    cin >> n >> m >> k;
	    vector<int> a(n), d(m), f(k);
	    for(int i = 0; i < n; i++){
	    	cin >> a[i];
	    }
	    for(int i = 0; i < m; i++){
	    	cin >> d[i];
	    }
	    for(int i = 0; i < k; i++){
	    	cin >> f[i];
	    }

	    vector<int> diff;
	    for(int i = 1; i < n; i++){
	    	int df = a[i] - a[i - 1];
	    	diff.push_back(df);
	    }

	    sort(all(diff));
	    int mnsecond = 0;

	    if(diff.size() >= 2){
	    	mnsecond = diff[diff.size() - 2];
	    	if(mnsecond == diff.back()){
	    		cout << mnsecond << "\n";
	    		return;
	    	}
	    }

	    int ind = 0;

	    for(int i = 1; i < n; i++){
	    	int df = a[i] - a[i - 1];
	    	if(df == diff.back()){
	    		ind = i - 1;
	    	}
	    }

	    sort(all(f));
	    sort(all(d));

	    int mnans = diff.back();

	    for(int i = 0; i < m; i++){
	    	int valf = a[ind] + diff.back() / 2 - d[i];

	    	int d1 = 1e18, d2 = 1e18;
	    	auto it = upper_bound(all(f), valf);

	    	if(it != f.end()){
	    		int x = *it;
	    		int val = d[i] + x;
	    		if(val >= a[ind] && val <= a[ind + 1]){
	    			d1 = max({val - a[ind], a[ind + 1] - val});
	    		}
	    	} 
	    	if(it != f.begin()){
	    		--it;
	    		int x = *it;
	    		int val = d[i] + x;
	    		if(val >= a[ind] && val <= a[ind + 1]){
	    			d2 = max({val - a[ind], a[ind + 1] - val});
	    		}
	    	}

	    	if(d1 != 1e18){
	    		mnans = min(mnans, max(mnsecond, d1));
	    	}
	    	if(d2 != 1e18){
	    		mnans = min(mnans, max(mnsecond, d2));
	    	}
	    }

	    cout << mnans << "\n";

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