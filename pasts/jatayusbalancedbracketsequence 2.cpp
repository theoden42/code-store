
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
#define int long long
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e6 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

void dfs(int source, vector<vector<int>> g, int n, vector<int>& vis){
	if(vis[source] == 1){
		return;
	}
	vis[source] = 1;
	for(auto& x: g[source]){
		dfs(x, g, n, vis);
	}
}

int countcomp(vector<vector<int>> g, int n){
	int count = 0;
	vector<int> vis(n, 0);
	for(int i = 0; i < n; i++){
		if(!vis[i]){
			count++;
			dfs(i, g, n, vis);
		}
	}
	return count;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = n + 1;
    int flag = 0;
    for(int i = 1; i < 2 * n; i++){
    	if(s[i] == ')' && s[i - 1] == '('){
    		ans--;
    	}
    }
    cout << ans << "\n";
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