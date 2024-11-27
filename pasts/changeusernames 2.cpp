
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


int dfs(int source, vector<int>& vis, vector<int>& instack, vector<vector<int>>& g){
	debug(source, instack);

	if(instack[source])return true;
	vis[source] = true;

	instack[source] = true;
	for(auto& x: g[source]){
		if(instack[x]){
			return true;
		}
		if(!vis[x] && dfs(x, vis, instack, g)){
			return true;
		}
	}
	instack[source] = false;
	return false;
}

void solve() {
    int n;
    cin >> n;
    map<string,int> mp;
    vector<pair<string, string>> vp(n);
    int count = 0;

    for(int i = 0; i < n; i++){
    	string s, t;
    	cin >> s >> t;
    	vp[i] = {s, t};
    	if(mp.find(s) == mp.end()){
    		mp[s] = count;
    		count++;
    	}
    	if(mp.find(t) == mp.end()){
    		mp[t] = count;
    		count++;
    	}
    }
    int sz = count + 1;
    debug(mp);

    vector<vector<int>> g(sz);
    for(int i = 0; i < n; i++){
    	string s, t;
    	s = vp[i].first;
    	t = vp[i].second;
    	int a = mp[s];
    	int b = mp[t];
    	g[a].push_back(b);
    }

    debug(g);



    // check for directed cycle in graph
   vector<int> vis(sz, 0);
   vector<int> instack(sz, 0);

   for(int i = 0; i < sz; i++){
   	if(!vis[i]){
   		if(dfs(i, vis, instack, g)){
   			debug(i);
   			cout << "No\n";
   			return;
   		}
   	}
   }


   cout << "Yes\n";

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    //cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}