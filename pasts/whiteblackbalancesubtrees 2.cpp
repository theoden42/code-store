	
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

	ll ans = 0;

	int countdepth(int source, vector<int>& depth, vector<vector<int>>& g, vector<int>& vis){
		vis[source] = 1;
		int mx = 0;
		for(auto x: g[source]){
			if(vis[x])
				continue;
			mx += countdepth(x, depth, g, vis);
		}
		mx += 1;
		depth[source] = mx;
		return depth[source];
	}	

	ll countbalance(int source, vector<int>& depth, string s, vector<vector<int>>& g, vector<int>& vis){
		vis[source] = 1;
		int count = 0;
		if(s[source - 1] == 'B')
			count++;
		for(auto x: g[source]){
			if(vis[x] == 1)continue;
			count += countbalance(x, depth, s, g, vis);
		}
		if(count == depth[source] - count){
			ans++;
		} 
		return count;
	}

	void solve() {
	    int n;
	    cin >> n;
	    vector<vector<int>> g(n + 1);
	    for(int i = 2; i <= n; i++){
	    	int x;
	    	cin >> x;
	    	g[x].push_back(i);
	    	g[i].push_back(x);
	    }	
	    string h;
	    cin >> h;
	    vector<int> depth(n + 1, 0);
	    vector<int> vis(n + 1, 0);
	    countdepth(1, depth, g, vis);
	    for(int i = 0; i <= n; i++){
	    	vis[i] = 0;
	    }
	    ans = 0;
	    countbalance(1 , depth, h, g, vis);
	    cout << ans << "\n";
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