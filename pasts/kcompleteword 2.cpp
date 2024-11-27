
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

void dfs(int source, vector<int>& vis, map<char,int>& mp, vector<vector<int>>& g, string& s, int& sz){
	vis[source] = 1;
	sz += 1;
	mp[s[source]] += 1;
	for(auto& x: g[source]){
		if(!vis[x]){
			dfs(x, vis, mp, g, s, sz);
		}
	}
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> g(n);

    for(int i = 0; i < n; i++){
    	g[i].push_back(n - 1 - i);
    }

    for(int i = 0; i < k; i++){

    	int j = i;
    	while(j < n){
    		if(j + k < n){
    			g[j].push_back(j + k);
    			g[j + k].push_back(j);
    		}
    		j += k;
    	}
    }

    vector<int> vis(n, 0);
    int count = 0;
    for(int i = 0; i < n; i++){
    	if(!vis[i]){
    		map<char,int> mp;
    		int sz = 0;
    		dfs(i, vis, mp, g, s, sz);
    		int mx = 0;
    		for(auto& x: mp){
    			mx = max(mx, x.second);
    		}
    		count += sz - mx;
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