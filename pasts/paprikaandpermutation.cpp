
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
	    vector<int> ele(n, 0);
	    for(int i = 0; i < n; i++){
	    	cin >> ele[i];
	    }
	    map<int,int> mp;
	    // for(int i = 0; i < n; i++){
	    // 	if(mp.find(ele[i]) != mp.end()){
	    // 		cout << "-1" << "\n";
	    // 		return;
	    // 	}
	    // 	else{
	    // 		mp[ele[i]] = 1;
	    // 	}
	    // }

	    // mp.clear();
	    
	    for(int i = 0; i < n; i++){
	    	if(ele[i] >= 0 && ele[i] <= n){
	    		if(mp.find(ele[i]) == mp.end()){
	    			mp[ele[i]] = 1;
	    			ele[i] = -1;
	    		}
	    	}
	    }
	    vector<int> vals;
	    for(int i = 0; i < n; i++){
	    	if(ele[i] != -1)
	    	vals.push_back(ele[i]);
	    }
	    sort(all(vals));
	    debug(mp);
		vector<int> need;
	    for(int i = 1; i <= n; i++){
	    	if(mp.find(i) == mp.end() && mp[i] != 1){
	    		need.push_back(i);
	    	}
	    }
	    sort(all(need));
	    int count = 0;
	    debug(need, vals);
	    for(int i = 0; i < (int)vals.size(); i++){
	    	if((vals[i] % 2 != 0 && need[i] > vals[i] / 2) || (vals[i] % 2 == 0 && need[i] >= vals[i] / 2)){
	    		cout << "-1" << "\n";
	    		return;
	    	}
	    	else{
	    		count++;
	    	}

	    }
	    cout << count << "\n";
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