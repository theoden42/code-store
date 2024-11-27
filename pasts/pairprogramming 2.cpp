	
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
	    int k, n, m;
	    cin >> k >> n >> m;
	    vector<int> a(n, 0);
	    vector<int> b(m, 0);
	    for(int i = 0; i < n; i++){
	    	cin >> a[i];
	    }
	    for(int i = 0; i < m; i++){
	    	cin >> b[i];
	    }
	    debug(a, b);
	    vector<int> ans;

	    int i = 0; 
	    int j = 0;
	    int line = k;

	    while(i < n && j < m){
	    	debug(a[i], b[j]);
	    	if(a[i] == 0){
	    		ans.push_back(a[i]);
	    		line++;
	    		i++;
	    		continue;
	    	}
	    	else if(b[j] == 0){
	    		ans.push_back(b[j]);
	    		line++;
	    		j++;
	    		continue;
	    	}

	    	if(a[i] < b[j]){
	    		if(a[i] > line){
	    			cout << -1 << "\n";
	    			return;
	    		}
	    		ans.push_back(a[i]);
	    		i++;
	    	}
	    	else{
	    		if(b[j] > line){
	    			cout << "-1" << "\n";
	    			return;
	    		}
	    		ans.push_back(b[j]);
	    		j++;
	    	}
	    }
	    while(i < n){
	    	if(a[i] == 0){
	    		line++;
	    	}
	    	else if(a[i] > line){
	    		cout << "-1" << "\n";
	    		return;
	    	}
	    	ans.push_back(a[i]);
	    	i++;
	    }
	    while(j < m){
	    	if(b[j] == 0){
	    		line++;
	    	}
	    	else if(b[j] > line){
	    		cout << "-1" << "\n";
	    		return;
	    	}
	    	ans.push_back(b[j]);
	    	j++;
	    }

	    for(auto& x: ans){
	    	cout << x << " ";
	    }
	    cout << "\n";
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