

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
    int n, m;
    cin >> n >> m;
    vector<string> vp(n);
    for(int i = 0; i < n; i++){
    	cin >> vp[i];
    }
    vector<int> row(n);
    vector<int> col(m);
    for(int i = 0; i < n; i++){
    	int c = 0;
    	for(int j = 0; j < m; j++) if(vp[i][j] == '#')
    		c += 1;
    	row[i] = c;
    }
    for(int i = 0; i < m; i++){
    	int c = 0;
    	for(int j = 0; j < n; j++) if(vp[j][i] == '#'){
    		c += 1;
    	}
    	col[i] = c;
    }
    vector<vector<int>> vis(n, vector<int>(m));
    auto check = [&](int i, int j){
    	return (i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && vp[i][j] == '#');
    };
    function<void(int, int, vector<pair<int,int>>&)> dfs = 
    [&](int i, int j, vector<pair<int,int>>& comp){
    	comp.push_back({i, j});
    	vis[i][j] = 1;
    	if(check(i - 1, j)){
    		dfs(i - 1, j, comp);
    	}
    	if(check(i, j - 1)){
    		dfs(i, j - 1, comp);
    	}
    	if(check(i + 1, j)){
    		dfs(i + 1, j, comp);
    	}
    	if(check(i, j + 1)){
    		dfs(i, j + 1, comp);
    	}
    };
    int mx = 0;

    vector<int> prefix_row(n + 2);
    vector<int> prefix_col(m + 2);
    vector<vector<int>> prefix_sub(n + 2, vector<int>(m + 2));
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++){
    		if(vis[i][j] || vp[i][j] != '#')
    			continue;
    		vector<pair<int,int>> comps;
    		dfs(i, j, comps);
    		int sz = comps.size();
    		mx = max(mx, sz);

    		sort(all(comps));
    		int left = m - 1, right = 0, top = n - 1, bottom = 0;
    		for(auto [x, y]: comps){
    			left = min(left, y);
    			right = max(right, y);
    			top = min(top, x);
    			bottom = max(top, x);
    		}
    		left = max(left - 1, 0);
    		right = min(right + 1, m - 1);
    		top = max(0, top - 1);
    		bottom = min(bottom + 1, n - 1);

    		prefix_col[left + 1] += sz;
    		prefix_col[right + 2] -= sz;
    		prefix_row[top + 1] += sz;
    		prefix_row[bottom + 2] -= sz;


    		prefix_sub[top + 1][left + 1] += sz;
    		prefix_sub[top + 1][right + 2] -= sz;
    		prefix_sub[bottom + 2][left + 1] -= sz;
    		prefix_sub[bottom + 2][right + 2] += sz; 
    	}
    }
    for(int i = 1; i <= n + 1; i++){
    	prefix_row[i] += prefix_row[i - 1];
    }
    for(int j = 1; j <= m + 1; j++){
    	prefix_col[j] += prefix_col[j - 1];
    }
    for(int i = 1; i <= n + 1; i++){
    	for(int j = 1; j <= m + 1; j++){
    		prefix_sub[i][j] += prefix_sub[i - 1][j];
    		prefix_sub[i][j] += prefix_sub[i][j - 1];
    		prefix_sub[i][j] -= prefix_sub[i - 1][j - 1];
    	}
    }
    for(int i = 1; i <= n; i++){
    	for(int j = 1; j <= m; j++){
    		int rc = prefix_row[i];
    		rc += prefix_col[j];
    		rc -= prefix_sub[i][j];
    		rc += (n + m - 1);
    		rc -= (row[i - 1] + col[j - 1] - (vp[i - 1][j - 1] == '#'));
    		mx = max(mx, rc);
    	}
    }

    cout << mx << "\n";
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