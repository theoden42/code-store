

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
    vector<string> s(n);
    map<int,int> rows, cols;
    for(int i = 0; i < n; i++){
    	cin >> s[i];
    	for(int j = 0; j < m; j++){
    		if(s[i][j] == '#'){
    			rows[i] = 1;
    			cols[j] = 1;
    		}
    	}
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < m; j++) if(s[i][j] != '#'){
    		queue<pair<int,int>> q;
    		vector<vector<int>> vis(n, vector<int>(m, 0));
    		q.push({i, j});
    		vis[i][j] = 1;
    		while(!q.empty()){
    			auto [r, c] = q.front();
    			q.pop();
    			if(rows[r] || cols[c])
    				continue;

    			if(r - 1 >= 0 && !vis[r - 1][c] && s[r - 1][c] != '#'){
    				vis[r - 1][c] = 1;
    				q.push({r - 1, c});
    			}
    			if(c - 1 >= 0 && !vis[r][c - 1] && s[r][c - 1] != '#'){
    				vis[r][c - 1] = 1;
    				q.push({r, c - 1});
    			}
    			if(r < n - 1 && !vis[r + 1][c] && s[r + 1][c] != '#'){
    				vis[r + 1][c] = 1;
    				q.push({r + 1, c});
    			}
    			if(c < m - 1 && !vis[r][c + 1] && s[r][c + 1] != '#'){
    				vis[r][c + 1] = 1;
    				q.push({r, c + 1});
    			}
    		}

    		int count = 0;
    		for(int i = 0; i < n; i++){
    			for(int j = 0; j < m; j++){
    				count += (vis[i][j]);
    			}
    		}

            debug(i, j, vis);
    		ans = max(ans, count);
    	}
    }

    cout << ans << "\n";

}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
   // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}